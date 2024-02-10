#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int solve(vector<int> &A) {

    int te = 0;
    int to = 0;

    for(int i = 0; i  < A.size(); i++)
    {
        if(i%2==0)
        te+=A.at(i);
        else
        to+=A.at(i);
    }

    int pe = 0;
    int po = 0;

    int ce = 0;
    int co = 0;

    int se = 0;

    for(int i = 0; i < A.size(); i++)
    {
        ce = 0;
        co = 0;

        if(i%2==0)
        ce=A.at(i);
        else
        co=A.at(i);

        int e = te - pe;
        int o = to - po;

        e -= ce;
        o -= co;

        if((pe+o) == (po+e))
        se++;

        pe+=ce;
        po+=co;
        
    }

    return se;
}