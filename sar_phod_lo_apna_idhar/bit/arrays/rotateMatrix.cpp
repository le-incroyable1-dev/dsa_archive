#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//s - starting point, len - length

void helper(vector<vector<int>> &A, int len, int si)
{
    if(len < 2)
    return;

    helper(A, len-2, si+1);

    int cur = A.size() - len;

    for(int i = 0; i < len-1; i++)
    {
        int c1 = A.at(si).at(si+i);
        int c2 = A.at(si+i).at(si+len-1);
        int c3 = A.at(si+len-1).at(si+len-1-i);
        int c4 = A.at(si+len-1-i).at(si);

        A.at(si).at(si+i) = c4;
        A.at(si+i).at(si+len-1) = c1;
        A.at(si+len-1).at(si+len-1-i) = c2;
        A.at(si+len-1-i).at(si) = c3;

    }

    return;

}

void rotate(vector<vector<int>> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0)
    return;

    helper(A, A.size(), 0);
    
    return;

}


