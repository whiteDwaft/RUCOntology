#include "xml_parse_generate.h"
#include <QDomDocument>
#include<QFile>
#include <QDomNode>
#include <string>
#include <vector>
#include <node.h>
#include <QDebug>

using namespace std;
Ontology *ontlg = new Ontology({});
Node *node1;
XML_parse_generate::XML_parse_generate(){}
QDomElement XML_parse_generate::makeElement(      QDomDocument& domDoc,
                                                  const QString&      argName,
                                                  const QString&      strName,
                                                  const QString&      strAttr,
                                                  const QString&      strText
                                                 )
{
    QDomElement domElement = domDoc.createElement(strName);

    if (!strAttr.isEmpty()) {
        QDomAttr domAttr = domDoc.createAttribute(argName);
        domAttr.setValue(strAttr);
        domElement.setAttributeNode(domAttr);
    }

    if (!strText.isEmpty()) {
        QDomText domText = domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}

QDomElement XML_parse_generate::contact(      QDomDocument& domDoc,
                                              const QString&      strName,
                                              const vector<QString>      runtime_func_arr,
                                              const vector<QString>      runtime_arg_arr,
                                              const vector<Node*>      runtime_link_arr,
                                              const vector<Node*>      designtime_link_arr,
                                              const vector<QString>      designtime_func_arr,
                                              const vector<QString>      designtime_arg_arr,
                                              TPP::TPPs tpp
                   )
{
    static int nNumber = 1;

    QDomElement domElement = makeElement(domDoc,"tpp",
                                         "node",
                                         TPP().getTPP(tpp)
                                        );
    QDomNode nodes = domElement.appendChild(makeElement(domDoc,"","name","", strName));

    QDomNode func_nodes = domElement.appendChild(makeElement(domDoc,"","functions", ""));
    QDomNode arg_nodes = domElement.appendChild(makeElement(domDoc,"", "args", ""));
    QDomNode link_nodes = domElement.appendChild(makeElement(domDoc, "", "links", ""));


    for(int i = 0; i < runtime_func_arr.size();i++)
    {
        func_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","func",TPP().getTPP(tpp) == "tutoring"?"runtime":"",runtime_func_arr[i]));
    }
    for(int i = 0; i < runtime_arg_arr.size();i++)
    {
        arg_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","arg",TPP().getTPP(tpp) == "tutoring"?"runtime":"",runtime_arg_arr[i]));
    }
    for(int i = 0; i < designtime_func_arr.size();i++)
    {
        func_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","func",TPP().getTPP(tpp) == "tutoring"?"designtime":"",designtime_func_arr[i]));
    }
    for(int i = 0; i < designtime_arg_arr.size();i++)
    {
        arg_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","arg",TPP().getTPP(tpp) == "tutoring"?"designtime":"",designtime_arg_arr[i]));
    }
    for(int i = 0; i < runtime_link_arr.size();i++)
    {
        link_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","link",TPP().getTPP(tpp) == "tutoring"?"runtime":"",runtime_link_arr[i]->node_name));
    }
    for(int i = 0; i < designtime_link_arr.size();i++)
    {
        link_nodes.appendChild(makeElement(domDoc,TPP().getTPP(tpp) == "tutoring"?"mode":"","link",TPP().getTPP(tpp) == "tutoring"?"designtime":"",designtime_link_arr[i]->node_name));
    }
    nNumber++;

    return domElement;
}
Ontology* XML_parse_generate::traverseNode(const QDomNode& node )
{  
   QDomNode domNode = node.firstChild();
   while(!domNode.isNull()) {
       if(domNode.isElement()) {
          QDomElement domElement = domNode.toElement();
          if(!domElement.isNull()) {
              if(domElement.tagName() == "name") {
                  ontlg->addNode(node1);
                  node1 = new Node(domElement.text(),{},{},{},TPP().getObject(domElement.attribute("tpp")));
              }
              else if(domElement.tagName() == "functions"){
                  for(int i=0;i < domElement.childNodes().size();i++)
                  {
                     QDomElement domEl = domElement.childNodes().item(i).toElement();
                     if(!domEl.isNull()){
                         if(domEl.tagName() == "func"){
                             node1->add_func(domEl.attribute("mode")=="designtime"?false:true,domEl.text());
                         }
                     }
                  }
             }
              else if(domElement.tagName() == "args"){
                  for(int i=0;i < domElement.childNodes().size();i++)
                  {
                     QDomElement domEl = domElement.childNodes().item(i).toElement();
                     if(!domEl.isNull()){
                         if(domEl.tagName() == "arg"){
                             node1->add_func(domEl.attribute("mode")=="designtime"?false:true,domEl.text());
                         }
                     }
                  }
                  ontlg->addNode(node1);
             }
          }

       }
       traverseNode(domNode);
       domNode = domNode.nextSibling();
    }
   return ontlg;

}

