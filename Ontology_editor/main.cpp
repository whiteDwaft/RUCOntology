#include "choose.h"
#include "start.h"

#include <QCoreApplication>
#include <QDomDocument>
#include<QFile>
#include <QDomNode>
#include<xml_parse_generate.h>
#include<QTextStream>
#include<node.h>
#include<ontology.h>
#include<iostream>


#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
        Choose ui;
        ui.show();


        return app.exec();
}


//    {

//        XML_parse_generate xml;
//        Node *node1 = new Node("node_1",{},{},{});
//        Node *node2 = new Node("node_2",{},{},{});
//        Node *node3 = new Node("node_3",{},{},{});
//        QDomDocument doc("ontology");
//        QDomElement  domElement = doc.createElement("ontology");
//        doc.appendChild(domElement);
//        node1->add_func(true,"func_1");// это будет вводится с экрана в перспективе
//        node1->add_arg(true,"arg_1");//это будет вводится с экрана в перспективе
//        node1->add_func(false,"func_2");//это будет вводится с экрана в перспективе
//        node1->add_arg(false,"arg_2");//это будет вводится с экрана в перспективе

//        node2->add_func(true,"func_1");//это будет вводится с экрана в перспективе
//        node2->add_arg(true,"arg_1");//это будет вводится с экрана в перспективе
//        node2->add_func(false,"func_2");//это будет вводится с экрана в перспективе
//        node2->add_arg(false,"arg_2");//это будет вводится с экрана в перспективе
//        Ontology ontlg = Ontology({*node1,*node2,*node3});//эта строка и 38 это кринж кринжа
//        node2->add_link(ontlg,"node_1",true);// это будет вводится с экрана в перспективе
//        node2->add_link(ontlg,"node_2",true);// это будет вводится с экрана в перспективе
//        node1->add_link(ontlg,"node_1",true);// это будет вводится с экрана в перспективе
//        Ontology ontlg2 = Ontology({*node1,*node2,*node3});
//        QDomElement contact1 =
//            xml.contact(doc,node1->node_name,node1->runtime_func_arr,node1->runtime_arg_arr,node1->runtime_link_arr,node1->designtime_link_arr, node1->designtime_func_arr,node1->designtime_arg_arr);
//        QDomElement contact2 =
//            xml.contact(doc,node2->node_name,node2->runtime_func_arr,node2->runtime_arg_arr,node2->runtime_link_arr,node2->designtime_link_arr, node2->designtime_func_arr,node2->designtime_arg_arr);
//        ontlg2.build_runtime_adjacency_matrix(ontlg2.node_arr1);
//        QDomElement contact3 =
//            xml.contact(doc,node3->node_name,node3->runtime_func_arr,node3->runtime_arg_arr,node3->runtime_link_arr,node3->designtime_link_arr, node3->designtime_func_arr,node3->designtime_arg_arr);


////        std::cout << "" << endl;
////        ontlg2.build_designtime_adjacency_matrix(ontlg2.node_arr1);

////        domElement.appendChild(contact1);
////        domElement.appendChild(contact2);
////        domElement.appendChild(contact2);
////        QFile file("ontology.xml");
////        if(file.open(QIODevice::WriteOnly)) {
////            QTextStream(&file) << doc.toString();
////            file.close();
////        }
////        return 0;
//    }

