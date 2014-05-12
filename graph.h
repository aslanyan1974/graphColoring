#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class graph
{
    public:
        graph(int n = 0);
        void setSize(int n);
        int getSize(){return vertexNum;}
        bool isEdge(int i, int j);
        void setEdge(int vertex1, int vertex2) {adjacentMatrix[vertex1][vertex2] = adjacentMatrix[vertex2][vertex1] = 1;}

        void input();
        void print();
        void setNCubic(int n);

    protected:
        int vertexNum;
        vector<vector <int> > adjacentMatrix;



};

void binary(int m, vector<int> &v);

#endif // GRAPH_H
