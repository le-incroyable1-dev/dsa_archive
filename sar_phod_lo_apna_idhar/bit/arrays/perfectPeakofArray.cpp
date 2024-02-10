#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int perfectPeak(vector<int> &A) {

    bool found = false;
    int peak;
    int cmax = INT_MIN;
    
    for(int i = 1; i < A.size(); i++)
    {
        cmax = max(A.at(i-1), A.at(i), cmax);

        if(found)
        {
            int m = min(A.at(i-1), A.at(i));
            if(m == A.at(i-1) && A.at(i) != A.at(i-1))
            {
                A.at(i) = m;
            }
            else
            {
                found = false;
            }

            continue;
        }

        if(A.at(i) > A.at(i-1) && A.at(i) == cmax && i!=A.size()-1)
        {
            found = true;
            peak = A.at(i);
        }
        else
        {
            A.at(i) = cmax;
        }
    }

    if(found)
    return 1;
    else
    return 0;


    
}