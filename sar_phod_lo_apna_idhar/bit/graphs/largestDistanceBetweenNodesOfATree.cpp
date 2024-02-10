#include <bits/stdc++.h>
using namespace std;


int res;
int helper(vector<int> adj[], int s){

    int ld = -1;
    int sld = -1;

    for(auto val : adj[s]){
        int dist = helper(adj, val);

        if(dist > ld){
            sld = ld;
            ld = dist;
        }
        else if(dist > sld)
        sld = dist;
    }

    res = max(res, max(sld, 0) + max(ld, 0));
    return ld + 1;

}

int max_dist(vector<int> adj[], int s){

    int add = INT_MIN;
    for(auto val : adj[s]){
        add = max(add, max_dist(adj, val));
    }

    if(add == INT_MIN)
    return 1;
    else
    return (add + 1);

}


int solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> adj[n];

    int root_node = -1;

    for(int i = 0; i < n; ++i){
        if(A[i] == -1){
            root_node = i;
            continue;
        }

        adj[A[i]].push_back(i);
    }

    // int ld = -1;
    // int sld = -1;
    
    // int index = 0;
    
    // int ans;
    
    // while(index < n){
        
    //     ld = -1;
    //     sld = -1;
        
    //     int cur;
        
    //     for(auto val : adj[index]){
    //         int dist = max_dist(adj, val);

    //         if(ld == -1)
    //         ld = dist;
    //         else if(sld == -1){
    //             if(dist > ld){
    //                 sld = ld;
    //                 ld = dist;
    //             }
    //             else{
    //                 sld = dist;
    //             }
    //         }
    //         else if(dist > ld){
    //             sld = ld;
    //             ld = dist;
    //         }
    //         else if(dist > sld)
    //         sld = dist;
            
    //         cur = max(ld, 0) + max(sld, 0);
    //         ans = max(ans, cur);
            
    //     }
        
    //     index++;
    
    // }

    
    return res;
    
}

int main(){

    vector<int> A = {-1, 0, 0, 0, 3};
    cout << solve(A);
    return 0;
}