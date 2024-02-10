#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define ll long long



//OP

// Is it possible to have at most t time taken under A painters?
bool possibleAtMostK(vector<ll> T,int A,ll t){

    int paintersReqd = 1;
    ll curSum = 0;

    for(int i = 0; i < T.size(); i++){

        if(T.at(i) > t)
        return false;

        if(curSum + T.at(i) > t){
            curSum = T.at(i);
            paintersReqd++;

            if(paintersReqd > A)
            return false;
        }
        else
        curSum += T.at(i);

    }

    return true;

}

int paint(int A, int B, vector<int> &C) {

    int n = C.size();

    vector<ll> T; //stores time taken for ith board

    ll sum = 0;

    for(auto el : C){ //for every element el in container C
        T.push_back((ll)el*B); //to avoid overflow ll was used
        sum += (ll)el*B;
    }

    ll start = 0;
    ll end = sum;

    ll mid;

    ll ans = LLONG_MAX;

    while(start <= end){

        mid = (start+end)/2;

        if(possibleAtMostK(T, A, mid)){
            ans = min(mid, ans);
            end = mid - 1;
        }
        else
        start = mid + 1;
    }

    return ((int)(ans % 10000003)); // take mod and return the value as an integer

}
