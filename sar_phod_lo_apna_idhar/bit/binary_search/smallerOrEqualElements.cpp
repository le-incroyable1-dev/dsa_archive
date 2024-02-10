#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, int B) {

    int i;
    
    vector<int>::iterator itr;
    itr = upper_bound(A.begin(),A.end(),B);
    //Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
    
    i=itr-A.begin();
    return i;

}

/*
EDITORIAL

int Solution::solve(vector<int> &a, int k) {
    int l=0;
    int r=a.size()-1;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=k)
        {
            ans=mid+1;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

*/