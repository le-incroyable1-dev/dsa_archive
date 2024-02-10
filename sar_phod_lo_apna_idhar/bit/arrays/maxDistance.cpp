#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> helper(vector<int> &v, int n)
{
    if(v.size() == 2)
    {
        pair<int, int> p;
        p.first = v.at(v.size()-1) - v.at(v.size() -2);
        p.second = max(v.at(v.size()-1), v.at(v.size()-2));
        return p;
    }

    pair<int,int> prev = helper(v, n-1);    

    int max = prev;

    int cur = v.at(v.size()-n);

    for(int i = v.size()-n+1; i < v.size(); i++)
    {
        if(v.at(i) - cur > max)
        max = v.at(i) - cur;
    }

    return max;    
}

int maximumGap(const vector<int> &A) {

    if(A.size() < 2)
    return 0;

    vector<pair<int, int>> pv;
    vector<int> arr = A;

    for(int i = 0; i < A.size(); i++)
    {
        pair<int, int> p;
        p.first = A.at(i);
        p.second = i;
        pv.push_back(p);
    }

    sort(pv.begin(), pv.end());

    vector<int> indices;

    for(int i = 0; i < pv.size(); i++)
    {
        indices.push_back(pv.at(i).second);
    }

    return helper(indices, indices.size()).first;

}


