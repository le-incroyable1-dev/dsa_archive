#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A) {
    
    int n = A.size();
    int profit = 0;
    
    for(int i = 1; i < n; ++i){
        if(A[i] > A[i-1])
        profit += A[i] - A[i-1];
    }
    
    return profit;
}
