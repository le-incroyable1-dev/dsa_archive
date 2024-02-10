#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


//EDITORIAL
//G MRGYI

/*

*SIGMA MOVE*
Note: numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since 
the missing positive integer will be in the range [1, N+1].

The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].

Creating buckets would have been an easy solution if using extra space was allowed.

An array of size N initialized to 0 would have been created.

For every value A[i] which lies in the range [1, N], its count in the array would have been incremented.

Finally, traversing the array would help to find the first array position with value 0 and that will be our answer.
However, usage of buckets is not allowed, can we use the existing array as bucket somehow?

Now, since additional space is not allowed either, the given array itself needs to be used to track it.

It may be helpful to use the fact that the size of the set we are looking to track is [1, N]

which happens to be the same size as the size of the array.

This means we can use the array to track these elements.

We traverse the array and if A[i] is in [1,N] range, we try to put in the index of same 
value in the array.
*/


int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}

        

/*

//MEMORY LIMIT EXCEEDED :(

#include <vector>
#include <algorithm>

int Solution::firstMissingPositive(vector<int> &A) {

    int ans = 1;

    if(A.size() == 0){
        return ans;
    }

    if(A.size() == 1){

        if(A.at(0) > 0)
        ans = A.at(0) + 1;

        return ans;
    }

    sort(A.begin(), A.end());

    int miss = 0;

    unordered_set<int> ele;
    unordered_set<int>::iterator itr;

    for(int i = 0; i < A.size(); i++)
    ele.insert(A.at(i));

    for(int i = 1; i < A.size(); i++){
        if(A.at(i-1) > 0 && A.at(i) - A.at(i-1) > 1){
            miss = A.at(i-1) + 1;
            break;
        }
    }


    // unordered set will check the existence of the element in constant time
    // find for vector will result in linear time for each i(not acceptable)

    for(int i = ans; i < miss; i++){
        itr = ele.find(i);
        if(itr == ele.end()){
            miss = i;
            break;
        }
    }

    if(miss != 0)
    ans = miss;

    if(miss == 0){
        for(int i = 0; i < A.size(); i++){
            if(A.at(i) > 0 && A.at(i) == ans){
                ans++;
            }
        }
    }

    return ans;
}

*/