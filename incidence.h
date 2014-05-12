#ifndef INCIDENCE_H
#define INCIDENCE_H

#include <utility>
using namespace std;

struct incidence
{
    incidence(const int v1 = 0,const int v2 = 0,const int c = -1);
    void setIncidence(const int v1 = 0,const int v2 = 0,const int c = -1);


    int vertex1;
    int vertex2;
    int color;
};

bool incAdjacent(const incidence &i1,const incidence &i2);

#endif // INCIDENCE_H
