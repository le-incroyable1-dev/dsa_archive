#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    
    vector<int> result;
    int carry = 1;
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A.at(i) == 9 && carry == 1)
        {
            result.push_back(0);
            carry = 1;
        }
        else
        {
            if(carry == 1)
            {
                result.push_back(A.at(i) + 1);
                carry = 0;
            }
            else
            {
                result.push_back(A.at(i));
            }
        }
    }

    if(carry == 1)
    {
        result.push_back(1);
    }

    reverse(result.begin(), result.end());
    return result;
}
