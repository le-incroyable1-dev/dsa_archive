#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> subUnsort(vector<int> &A) {

    vector<int> res;

    if(A.size() < 2)
    {
        res.push_back(-1);
        return res;
    }

    int i = 0;
    int j = A.size()-1;
    int si = -1;
    int ei = -1;

    while(i < A.size()-1 && j > 0)
    {
        if(j <= i && si==-1 && ei==-1)
        {
            res.push_back(-1);
            return res;
        }

        if(si!=-1 && A.at(i+1) < A.at(i))
        {
            si = i;
        }

        if(ei!=-1 && A.at(j-1) > A.at(j))
        {
            ei = j;
        }

        if(si != -1 && ei != -1)
        break;

        i++;
        j--;

    }

    if(si==-1 && ei==-1)
    {
        res.push_back(-1);
        return res;
    }

    if(si < A.size()-1 && A.at(si-1) == A.at(si))
    {
        while(si < A.size() - 1 && A.at(si-1) == A.at(si))
        {
            si--;
        }
    }

    if(ei > 0 && A.at(ei+1) == A.at(ei))
    {
        while(ei > 0 && A.at(ei+1) == A.at(ei))
        {
            ei++;
        }
    }


    res.push_back(si);
    res.push_back(ei);

    return res;

}
//15 3 3 4 5 5 9 11 13 14 15 15 16 15 20 16
