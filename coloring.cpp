#include "coloring.h"

coloring::coloring(int n) : graph(n)
{
    colorMatrix.reserve(n);
    for(int i = 0; i < vertexNum; i++)
        colorMatrix[i].reserve(n);

    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < vertexNum; j++)
            colorMatrix[i][j] = -1;
}



void coloring::printColors()
{
    for(int i = 0; i < vertexNum; i++)
    {
        for(int j = 0; j < vertexNum; j++)
            cout << " " << colorMatrix[i][j] ;
        cout << endl;
    }
}

bool plusVector(vector<int> & v, int k)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if(*it < k)
        {
            ++(*it);
            return true;
        }
        while(it != v.end())
        {
            (*it) = 0;
            if(++it == v.end())
                return false;

            if(*it < k)
            {
                ++(*it);
                return true;
            }
        }
        return false;
    }
    return false;
}



bool coloring::setColoring(int k)
{
    int edgeNum = 0;
    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < i; j++)
            if(adjacentMatrix[i][j])
                edgeNum++;

    vector<int> m(edgeNum + edgeNum,0);
    int index;

    while(plusVector(m,k))
    {
        index = 0;
//        for(int i = 0; i < (edgeNum + edgeNum); i++)
//            cout << m[i] << " ";
//        cout << endl;
        for(int i = 0; i < vertexNum; i++)
        {
            for(int j = 0; j < vertexNum; j++)
            {
                if(adjacentMatrix[i][j])
                {
                    colorMatrix[i][j] = m[index++];
                }
            }
        }
        //printColors();
        if(proper())
        {
            cout << "- ";
            for(int i = 0; i < vertexNum; i++)
                    cout << "   " << i;
            cout << endl;

            for(int i = 0; i < vertexNum; i++)
            {
                cout << i;
                for(int j = 0; j < vertexNum; j++)
                    cout << "   " << colorMatrix[i][j] ;
                cout << endl;
            }
            return true;
        }
    }
    return false;
}


bool coloring::proper()
{
    for(int i = 0; i < vertexNum; i++)
        for(int j = 0; j < vertexNum; j++)
        {
            int current = colorMatrix[i][j];
            if(current >= 0)
            {
                //i -ov sksvoxner@
//                for(int k = 0; k < j; k++)
//                {
//                    if(current == colorMatrix[i][k])
//                        return false;
//                }

                for(int k = j + 1; k < vertexNum; k++)
                {
                    if(current == colorMatrix[i][k])
                        return false;
                }

                //j-ov sksvoxner@, hnaravor a k=0
                for(int k = i; k < vertexNum; k++)
                {
                    if(current == colorMatrix[j][k])
                        return false;
                }
                //i-ov verjacoxner@ hnaravor a k=0
                for(int k = j; k < vertexNum; k++)
                {
                    if(current == colorMatrix[k][i])
                        return false;
                }
            }
        }
    return true;
}














