#include "incidence.h"

incidence::incidence(const int v1, const int v2, const int c) : vertex1(v1), vertex2(v2), color(c)
{}


void incidence::setIncidence(const int v1, const int v2, const int c)
{
    vertex1 = v1;
    vertex2 = v2;
    color = c;
}


bool incAdjacent(const incidence& i1,const incidence& i2)
{
    if((i1.vertex1 == i2.vertex1)
            || (i1.vertex2 == i2.vertex1)
            || (i1.vertex1 == i2.vertex2) )
        return true;
    return false;
}
