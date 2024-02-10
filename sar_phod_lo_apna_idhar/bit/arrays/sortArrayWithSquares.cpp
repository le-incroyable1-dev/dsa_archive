#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


vector<int> solve(vector<int> &A) {

    vector<int> p;
    vector<int> n;

    for(int i = 0; i < A.size(); i++)
    {
        if(A.at(i) < 0)
        {
            n.push_back(A.at(i)*A.at(i));
        }
        else
        {
            p.push_back(A.at(i)*A.at(i));
        }
    }

    reverse(n.begin(), n.end());

    vector<int> res;

    int i = 0;
    int j = 0;

    while(i < p.size() && j < n.size())
    {
        if(p.at(i) < n.at(j))
        {
            res.push_back(p.at(i));
            i++;
        }
        else
        {
            res.push_back(n.at(j));
            j++;
        }
    }

    for(i; i < p.size(); i++)
    {
        res.push_back(p.at(i));
    }

    for(j; j < n.size(); j++)
    {
        res.push_back(n.at(j));
    }

    return res;
}
