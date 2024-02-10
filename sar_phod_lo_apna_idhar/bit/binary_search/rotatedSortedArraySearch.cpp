#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>

using namespace std;

#define ll long long
#define ld long double


//find pivot OP
int findPivot(const vector<int> &A){
    int l=0,h=A.size()-1;
    while(l<=h){
        
        int mid=h-(h-l)/2;


        // *SIGMA MOVE INCOMING*
 
        if(A[mid]>A[0])
        l=mid+1;
        else
        h=mid-1;
    }

    return h;
    
}


//standard binary search
int isPresent(const vector<int> &A,int l,int h,int val){
    
    while(l<=h){
        int mid=h-(h-l)/2;
        if(A[mid]==val)
            return mid;
        else if(A[mid]<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
    
    
}

int search(const vector<int> &A, int B) {
    int pivot=findPivot(A);
    if(B==A[pivot])
        return pivot;
    else if(B<A[0])
        return isPresent(A,pivot+1,A.size()-1,B);
    else
        return isPresent(A,0,pivot,B);
}