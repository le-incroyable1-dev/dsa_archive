#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ll l = 0;
    ll r = A.size()-1;

    if(l > r)
    return -1;
    else if(l == r){
        if(A.at(0) <= B)
        return 0;

        return 1;
    }

    if(A.at(0) >= B)
    return 0;

    if(A.at(r) == B)
    return r;
    
    if(A.at(r) < B)
    return r+1;

    ll pi = -1; //index of smaller element


    while(l <= r){

        ll mid = (l+r)/2;

        if(A.at(mid) == B)
        return (int)mid;

        if(A.at(mid) > B)
        r = mid - 1;

        if(A.at(mid) < B){
            pi = mid;

            l = mid + 1;
        }
    }

    pi++; //will insert at the next index of the index where the largest element smaller than B is present

    return (int)pi;
}