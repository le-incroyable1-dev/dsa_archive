#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int maxProd(vector<int> &sum, vector<vector<int>> &adj, int cur, vector<bool> &vis){

    int prod = INT_MIN;
    vis[cur] = true;

    for(auto val : adj[cur]){
        
        if(vis[val])
        continue;
        
        int cur = (((sum[cur]-sum[val])%mod) * (sum[val]%mod))%mod;
        prod = max(prod, max(cur, maxProd(sum, adj, val, vis)));
    }
    
    if(prod == INT_MIN)
    return 0;
    
    return prod%mod;
}

int getSum(vector<int> &sum, vector<int> &wts, vector<vector<int>> &adj, int cur, vector<bool> &vis){

    int res = 0;
    vis[cur] = true;

    for(auto val : adj[cur]){

        if(!vis[val])
        res += getSum(sum, wts, adj, val, vis)%mod;
    }

    res += wts[cur]%mod;
    sum[cur] = res%mod;
    return res%mod;

}

int deleteEdge(vector<int> &wts, vector<vector<int> > &e) {

    int n = wts.size();
    vector<vector<int>> adj(n);
    vector<int> sum(n, 0);
    vector<bool> vis(n, false);

    for(auto vec : e){
        adj[vec[0]-1].push_back(vec[1]-1);
        adj[vec[1]-1].push_back(vec[0]-1);
    }

    int s = getSum(sum, wts, adj, 0, vis);
    
    for(int i = 0; i < n; ++i)
    vis[i] = false;
    return maxProd(sum, adj, 0, vis)%mod;
}

int main(){

    vector<int> wts = {10,5,12,6};
    //vector<vector<int>> e 
}

