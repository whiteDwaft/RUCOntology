#ifndef XML_PARSE_GENERATE_H
#define XML_PARSE_GENERATE_H
#include<QDomDocument>
#include <string>
#include <vector>
#include <node.h>

using namespace std;
class XML_parse_generate
{
public:
    XML_parse_generate();
    QDomElement makeElement(      QDomDocument& domDoc,
                            const QString&      strName,
                            const QString&      argName = QString::null,
                            const QString&      strAttr = QString::null,
                            const QString&      strText = QString::null
                           );
    QDomElement contact(      QDomDocument& domDoc,
                        const QString&      strName,
                        const vector<QString>      runtime_func_arr,
                        const vector<QString>      runtime_arg_arr,
                        const vector<Node*>      runtime_link_arr,
                        const vector<Node*>      designtime_link_arr,
                        const vector<QString>      designtime_func_arr,
                        const vector<QString>      designtime_arg_arr,
                              TPP::TPPs tpp
                       );
    Ontology* traverseNode(const QDomNode& node);
};



#endif // XML_PARSE_GENERATE_H
