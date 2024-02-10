#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

vector<int> searchRange(const vector<int> &A, int B) {

    ll l = 0;
    ll r = A.size()-1;

    vector<int> res;

    res.push_back(-1);
    res.push_back(-1);

    if(l > r)
    return res;
    else if(l == r){
        if(A.at(0) == B){
            res.clear();
            res.push_back(0);
            res.push_back(0);
        }
        return res;
    }

    
    ll fi = -1;
    ll mi = -1;
    ll ei = -1;

    while(l <= r){

        ll mid = (l+r)/2;

        if(A.at(mid) >= B){
            if(A.at(mid) == B && mi == -1)
            mi = mid;
            else if(A.at(mid) == B && mi != -1)
            fi = mid;

            r = mid - 1;
        }

        if(A.at(mid) < B)
        l = mid + 1;

    }

    if(mi == -1)
    return res;

    if(fi == -1)
    fi = mi;

    l = mi+1;
    r = A.size()-1;

    while(l <= r){

        ll mid = (l+r)/2;

        if(A.at(mid) == B){
            ei = mid;
            l = mid + 1;
        }

        if(A.at(mid) > B)
        r = mid - 1;
    }

    if(ei == -1)
    ei = mi;

    /*
    if(fi > ei)
    fi = ei;
    */

    res.clear();
    res.push_back((int)fi);
    res.push_back((int)ei);

    return res;
}
