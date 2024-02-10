#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int A) {

    vector<int> res;

    if(A == 0)
    {
        res.push_back(1);
        return res;
    }
    else if(A == 1)
    {
        res.push_back(1);
        res.push_back(1);

        return res;
    }
    else{

        vector<int> prev = getRow(A-1);

        res.push_back(1);

        for(int i = 0; i < prev.size() -1; i++)
        {
            int el = prev.at(i) + prev.at(i+1);
            res.push_back(el);
        }

        res.push_back(1);

        return res;
    }

}
