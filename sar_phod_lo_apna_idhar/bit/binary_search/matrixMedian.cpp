#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define ll long long

/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns 
are numbered from left to right.

Input Format
The first and only argument given is the integer matrix A.

Output Format
Return the overall median of the matrix A.

Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
*/

/*
We cannot use extra memory, so we can’t actually store all elements in an array and sort the array.
But since, rows are sorted it must be of some use, right?

Note that in a row you can binary search to find how many elements are smaller than a value X in O(log M).
This is the base of our solution.

Say k = N*M/2. We need to find (k + 1)^th smallest element.
We can use binary search on answer. In O(N log M), we can count how many elements are smaller than X in the matrix.

//
*SIGMA MOVE*
So, we use binary search on interval [1, INT_MAX]. So, total complexity is O(30 * N log M).
//

Note:
This problem can be solve by using min-heap, but extra memory is not allowed.

*/

//LIGHTWEIGHT SOLUTION (ACCORDING TO EXPLANATION)

int LessNums(const vector<int> &A, const int num) {
    const int N = A.size();
    int lo = 0, hi = N - 1;
    
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        
        if (A[m] >= num) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    
    return (A[lo] >= num) ? lo : N;
}

int LessNums(const vector<vector<int>> &A, const int num) {
    const int M = A.size();
    
    int ans = 0;
    
    for (int i = 0; i < M; i++) {
        ans += LessNums(A[i], num);
    }
    
    return ans;
}

int findMedian(vector<vector<int> > &A) {
    const int M = A.size();
    const int N = A[0].size();
    const int target_index = (M * N) / 2;
    
    int lo = 0, hi = numeric_limits<int>::max() - 1;
    while (lo < hi) {
        int m = lo + (hi - lo + 1) / 2;
        
        int lessnums = LessNums(A, m);
        if (lessnums <= target_index) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    
    return lo;
}


//EDITORIAL
//USES UPPER_BOUND TO AVOID TLE

int findMedian(vector<vector<int> > &a) {

    int n=a.size(),m=a[0].size();
    int mi=INT_MAX,ma=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mi=min(mi,a[i][0]);
    }
    for(int i=0;i<n;i++)
    {
        ma=max(ma,a[i][m-1]);
    }
    int ind=((n*m)+1)/2;
    while(mi<ma)
    {
        int mid=mi+(ma-mi)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=count+upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        }
         if(count<ind)
             mi=mid+1;
           else
             ma=mid;
    }
    return mi;
    
}

