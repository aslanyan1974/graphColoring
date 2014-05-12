#include "graph.h"
#include "math.h"
#include "stdlib.h"

void binary(int m, vector<int> &v)
{
    vector<int>::iterator it;

    it = v.begin();

    while(m > 1)
    {
        if(m & 1)
            *it = 1;
        else
            *it = 0;
        m /= 2;
        it++;
    }
    *(it++) = m;
    for(; it != v.end(); ++it)
        *it = 0;

//    for(it = v.begin(); it != v.end(); ++it)
//        cout << *it << " ";
//    cout << endl;
}

graph::graph(int n):vertexNum(n)
{
    adjacentMatrix.reserve(n);
    for(int i = 0; i < vertexNum; i++)
        adjacentMatrix[i].reserve(n);

    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < vertexNum; j++)
            adjacentMatrix[i][j] = 0;
}

void graph::setSize(int n)
{
    vertexNum = n;
    adjacentMatrix.reserve(n);
    for(int i = 0; i < vertexNum; i++)
        adjacentMatrix[i].reserve(n);
}


bool graph::isEdge(int i, int j)
{
    if(adjacentMatrix[i][j])
        return true;
    return false;
}



void graph::input()
{
    cout << "input size\n";
    cin >> vertexNum;

    adjacentMatrix.reserve(vertexNum);
    for(int i = 0; i < vertexNum; i++)
        adjacentMatrix[i].reserve(vertexNum);

    cout << "input edges\n";
    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < vertexNum; j++)
            cin >> adjacentMatrix[i][j];
}

void graph::print()
{
    cout << "size = " << vertexNum << endl;
    for(int i = 0; i < vertexNum; i++)
    {
        for(int j = 0; j < vertexNum; j++)
            cout << adjacentMatrix[i][j] << " ";
        cout << endl;
    }
}



void graph::setNCubic(int n)
{
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    int div = 0;

    vertexNum = pow(2,n);

    for(int i = 0; i < vertexNum; i++)
        for(int j = i+1; j < vertexNum; j++)
        {
            binary(i,v1);
            binary(j,v2);
            for(it1 = v1.begin(), it2 = v2.begin() ; it1 != v1.end(); ++it1, ++it2)
            {
                div += abs(*it1 - *it2);
            }
            if(div == 1)
                this ->setEdge(i, j);
            div = 0;
        }
}
















