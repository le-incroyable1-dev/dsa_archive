#include <iostream>
#include <vector>
using namespace std;


/*
NOTE:
A Bitonic Sequence is a sequence of numbers which is 
first strictly increasing then after a point strictly decreasing.
*/

int findBitonicIndex(vector<int> v, int si, int ei){

    int mid = (si+ei)/2;
    
    if(si > ei)
    return -1;

    if(v.at(mid) > v.at(mid-1) && v.at(mid) > v.at(mid+1))
    return mid;
    
    if(v.at(mid) < v.at(mid+1))
    return findBitonicIndex(v, mid+1, ei);
    else
    return findBitonicIndex(v, si, mid-1);

}

int BinarySearchLeft(vector<int>& array, int key, int lower, int upper) {

while (lower <= upper) {
    int mid = lower + (upper-lower) /2;
    if(key == array.at(mid))
    {
        return mid;
    }
    if(key < array.at(mid))
        upper = mid-1;
    else
        lower = mid+1;
}

return -1;
}


int BinarySearchRight(vector<int>& array, int key, int lower, int upper) {

while (lower <= upper) {
    int mid = lower + (upper-lower) /2;
    if(key == array.at(mid))
    {
        return mid;
    }
    if(key > array.at(mid))
        upper = mid-1;
    else
        lower = mid+1;
}

return -1;
}

int solve(vector<int> &A, int B) {

    int n = A.size();
    int mid = (n+1)/2;

    if(n == 0)
    return -1;

    if(n==1){
        if(A.at(0) == B)
        return 0;
        else
        return -1;
    }

    int bi = findBitonicIndex(A, 0, A.size()-1);
    //cout << bi << endl;

    //cout << BinarySearchRight(A, B, bi+1, A.size()-1) << endl << BinarySearchLeft(A, B, 0, bi-1) << endl;

    if(A.at(bi) == B)
    return bi;
    else{
        
        if(BinarySearchRight(A, B, bi+1, A.size()-1) != -1)
        return BinarySearchRight(A, B, bi+1, A.size()-1);
        else
        return BinarySearchLeft(A, B, 0, bi-1);
    }

    return -1;
}

/*
20 1 2 3 4 5 6 7 8 9 10 20 19 18 17 16 15 14 13 12 11 
12
*/