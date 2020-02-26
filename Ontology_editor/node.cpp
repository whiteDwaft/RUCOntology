#include "node.h"
#include <algorithm>
#include <QString>
#include <ontology.h>
#include <cstring>
#include <iostream>

using namespace std;
Node::Node(QString node_name, vector <Node*> link_arr, vector <QString> arg_arr, vector <QString> func_arr,TPP::TPPs tpp)
{
    this->node_name = node_name;
    this->runtime_arg_arr = arg_arr;
    this->runtime_func_arr = func_arr;
    this->runtime_link_arr = link_arr;
    this->tpp = tpp;
}
void Node::del_func(QString func_name){
    runtime_func_arr.erase(std::find(runtime_func_arr.begin(),runtime_func_arr.end(),func_name));
}

void Node::del_func(int func_index){
    runtime_func_arr.erase(runtime_func_arr.begin()+func_index-1);
}

void Node::change_func(QString old_func_name, QString new_func_name){
    std::replace (runtime_func_arr.begin(), runtime_func_arr.end(), old_func_name,new_func_name);
}
void Node::add_func(bool is_runtime,QString func_name){
    if (is_runtime)
        runtime_func_arr.insert(runtime_func_arr.end(),func_name);
    else
        designtime_func_arr.insert(designtime_func_arr.end(),func_name);
}



//__________________________________________________с этими методами пока вылетает______________________________________________
//void Node::del_link(QString link_name){
//    for (int i = 0; i < link_arr.size(); i++)
//    {
//        if(link_arr[i].node_name.compare(link_name) == 0)
//        {
//            link_arr.erase(std::find(link_arr.begin(),link_arr.end(),link_arr[i]));
//        }
//    }
//}
//void Node::del_link(int link_index){
//    link_arr.erase(link_arr.begin()+link_index-1);
//}
//void Node::change_link(QString old_link_name, QString new_link_name){
//    for (int i = 0; i < link_arr.size(); i++)
//    {
//        if(link_arr[i].node_name.compare(old_link_name) != 0)
//        {
//            for (int j = 0; j < ontlg.node_arr.size(); i++)
//            {
//                if(ontlg.node_arr[j].node_name.compare(new_link_name) != 0)
//                {
//                    std::replace (link_arr.begin(), link_arr.end(), link_arr[i],ontlg.node_arr[j]);
//                }
//            }
//        }
//    }
//}
void Node::add_link(Ontology ontlg,QString link_name, bool is_runtime){
    for (int i = 0; i < ontlg.node_arr1.size(); i++)
    {
        if(ontlg.node_arr1[i]->node_name.compare(link_name) == 0)
        {
            if(is_runtime)
                runtime_link_arr.insert(runtime_link_arr.end(),ontlg.node_arr1[i]);
            else
                designtime_link_arr.insert(designtime_link_arr.end(),ontlg.node_arr1[i]);
        }
    }
}

QString Node::getNode_name() const
{
    return node_name;
}

void Node::setNode_name(const QString &value)
{
    node_name = value;
}




void Node::del_arg(QString arg_name){
    runtime_arg_arr.erase(std::find(runtime_arg_arr.begin(),runtime_arg_arr.end(),arg_name));
}

void Node::del_arg(int arg_index){
    runtime_arg_arr.erase(runtime_arg_arr.begin()+arg_index-1);
}

void Node::change_arg(QString old_arg_name, QString new_arg_name){
    std::replace (runtime_arg_arr.begin(), runtime_arg_arr.end(), old_arg_name,new_arg_name);
}
void Node::add_arg(bool is_runtime, QString arg_name){
    if(is_runtime)
        runtime_arg_arr.insert(runtime_arg_arr.end(),arg_name);
    else
        designtime_arg_arr.insert(designtime_arg_arr.end(),arg_name);
}
