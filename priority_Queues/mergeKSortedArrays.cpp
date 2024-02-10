
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//O(k*n*log(n))
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {

    vector<int> ans;

    int k = input.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < k; i++){
        for(auto val : *input[i])
            pq.push(val);
    }
    
    while(!pq.empty()){
        int val = pq.top();
        pq.pop();
        ans.push_back(val);
    }

    return ans;
}