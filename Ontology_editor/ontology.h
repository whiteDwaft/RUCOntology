#ifndef ONTOLOGY_H
#define ONTOLOGY_H
#include <vector>
#include<node.h>

using namespace std;
class Node;
class Ontology
{
// ____________________исправлю_________________
public:
    Ontology(vector <Node*> node_arr);

    vector <Node*> node_arr1;
    void build_runtime_adjacency_matrix(vector <Node*> node_arr);
    void build_designtime_adjacency_matrix(vector <Node*> node_arr);
    int eqv(int i, int j);
    void addNode(Node * node);
};

#endif // ONTOLOGY_H
