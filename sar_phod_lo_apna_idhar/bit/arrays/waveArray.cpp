#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> wave(vector<int> &A) {

    if(A.size() < 2)
    return A;

    sort(A.begin(), A.end());

    int i = 1;
    int len = A.size();
    vector<int> res;

    while(i < len)
    {
        res.push_back(A.at(i));
        res.push_back(A.at(i-1));

        i+=2;
    }

    if(i==len)
    res.push_back(A.at(len-1));

    return res;
}
