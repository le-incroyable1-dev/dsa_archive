#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> findPerm(const string A, int B) {

    vector<int> perm;

    if(A.size() == 0)
    return perm;
    else if (A.size() == 1)
    {
        if(A.at(0) == 'D')
        {
            perm.push_back(2);
            perm.push_back(1);
        }
        else if(A.at(0) == 'I')
        {
            perm.push_back(1);
            perm.push_back(2);
        }

        return perm;
    }

    int *arr = new int[B];

    for(int i = 0; i < B; i++)
    {
        arr[i] = i+1;
    }

    int i = 0;
    int j = B-1;
    int k = 0;

    while(i < B && j >= 0 && j>=i && k < A.length())
    {
        if(A.at(k) == 'D')
        {
            perm.push_back(arr[j]);
            j--;
        }
        else if(A.at(k) == 'I')
        {
            perm.push_back(arr[i]);
            i++;
        }
        else
        break;

        k++;

    }

    if(A.at(A.length() - 1) == 'D')
    {
        perm.push_back(arr[i]);
    }
    else if(A.at(A.length()-1) == 'I')
    {
        perm.push_back(arr[j]);
    }

    return perm;

}