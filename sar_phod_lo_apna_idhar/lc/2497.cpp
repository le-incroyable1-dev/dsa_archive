#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    vector<bool> vis;
    unordered_map<int, int> ss;
    //unordered_map<int, int> ne;
    int ans = INT_MIN;

    void move(vector<int> &vi, int &n, set<pair<int, int>> *g, int u, int k){

        vis[u] = true;

        int c = k;
        set<pair<int, int>>::iterator itr;

        int e = g[u].size();

        if(e > 0){
            itr = g[u].end();
            itr--;
        }
        
        while(e){
            if(c == 0) break;
            pair<int, int> p = *itr;
            int val = p.first; int v = p.second;
            
            if(val > 0){
                c--;
                ss[u] += val;
            }

            e--;
            itr--;
        }

        for(auto nxt : g[u]){
            if(vis[nxt.second]) continue;
            move(vi, n, g, nxt.second, k); 
        }

        return;
    }
    

    int maxStarSum(vector<int>& v, vector<vector<int>>& e, int k) {
        
        int n = v.size();
        for(int i = 0; i < n; ++i) ss[i] = v[i];
        set<pair<int, int>> g[n];
        vis.resize(n, false);
        for(auto p : e) g[p[0]].emplace(v[p[1]], p[1]), g[p[1]].emplace(v[p[0]], p[0]);
        
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            else move(v, n, g, i, k);
        }

        unordered_map<int, int> m = ss;
        for(auto p : m) ans = max(ans, p.second);
        return ans;
        
    }
};


int main(){
    vector<int> v = {-5};
    vector<vector<int>> e =  {
    };

    Solution sol;
    cout << sol.maxStarSum(v, e, 0) << "\n";
    return 0;
}