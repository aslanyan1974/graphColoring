#ifndef COLORING_H
#define COLORING_H

#include "graph.h"
#include "incidence.h"


class coloring : public graph
{
    public:
        coloring(int n = 0);
        bool setColoring(int k);
        void printColors();
        bool proper();

    private:
        vector<vector<int> > colorMatrix;
};

#endif // COLORING_H
