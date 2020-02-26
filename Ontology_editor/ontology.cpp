#include "ontology.h"
#include <vector>
#include<node.h>
#include <iostream>
using namespace std;
// ____________________исправлю_________________
Ontology::Ontology(vector <Node*> node_arr)
{
    this->node_arr1 = node_arr;


}
int Ontology::eqv(int i, int j)
{
    if(i == j)
        return true;
    else
        return false;
}
void Ontology::addNode(Node* node)
{
    node_arr1.insert(node_arr1.end(),node);
}
void Ontology::build_runtime_adjacency_matrix(vector <Node*> node_arr)
{
    int **runtime_adjMatrix = new int*[node_arr.size()];
    for (int i = 0; i < node_arr.size(); i++ )
    {
        runtime_adjMatrix[i] = new int[node_arr.size()];
        for(int j = 0; j < node_arr.size();j++)
        {
            std::cout.width(node_arr.size());
            runtime_adjMatrix[i][j] = 0;
            if (!node_arr[i]->runtime_link_arr.empty())
            {
                for (int k = 0; k < node_arr[i]->runtime_link_arr.size();k++)
                {
                    if (node_arr[i]->runtime_link_arr[k]->node_name.compare(node_arr[j]->node_name) == 0)
                        runtime_adjMatrix[i][j] = 1;
                }
            }
            std::cout << runtime_adjMatrix[i][j];
        }
        std::cout << "" << endl;
    }
}

void Ontology::build_designtime_adjacency_matrix(vector <Node*> node_arr)
{
    int **designtime_adjMatrix = new int*[node_arr.size()];
    for (int i = 0; i < node_arr.size(); i++ )
    {
        designtime_adjMatrix[i] = new int[node_arr.size()];
        for(int j = 0; j < node_arr.size();j++)
        {
            std::cout.width(node_arr.size());
            designtime_adjMatrix[i][j] = 0;
            if (!node_arr[i]->designtime_link_arr.empty())
            {
                for (int k = 0; k < node_arr[i]->designtime_link_arr.size();k++)
                {
                    if (node_arr[i]->designtime_link_arr[k]->node_name.compare(node_arr[j]->node_name) == 0)
                        designtime_adjMatrix[i][j] = 1;
                }
            }
            std::cout << designtime_adjMatrix[i][j];
        }
        std::cout << "" << endl;
    }
}

