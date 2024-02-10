#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(int A) {

    vector<vector<int>> res;

    if(A == 0)
    {
        return res;
    }
    else if(A == 1)
    {
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        return res;
    }
    else if(A == 2)
    {
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        temp.push_back(1);
        res.push_back(temp);
        return res;
    }
    else{
        vector<vector<int>> prev = solve(A-1);

        vector<int> newRow;
        vector<int> prevRow = prev.at(prev.size()-1);

        newRow.push_back(1);

        for(int i = 0; i < prevRow.size() -1; i++)
        {
            int el = prevRow.at(i) + prevRow.at(i+1);
            newRow.push_back(el);
        }

        newRow.push_back(1);
        prev.push_back(newRow);

        return prev;

    }
}
