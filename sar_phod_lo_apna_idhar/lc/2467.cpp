#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> *g;
    unordered_map<int, int> dzm, dbm;

    void store_par(int i, int d, int par, vector<int> &vp){    
        if(i) vp[i] = par;
        dzm[i] = d;

        for(auto v : g[i]){
            if(v == par) continue;
            store_par(v, d+1, i, vp);
        }

        return;
    }

    void move_bob(int i, int d, vector<int> &vp){
        dbm[i] = d;
        if(i) move_bob(vp[i], d+1, vp);
        return;
    }

    int solve(int i, vector<int> &a, int par){
        int score = 0;
        if(dbm.find(i) != dbm.end()){
            if(dbm[i] < dzm[i]) score += 0;
            else if(dbm[i] == dzm[i]) score += a[i]/2;
            else score += a[i];
        }
        else score += a[i];

        int add = INT_MIN;
        if(g[i].size() == 1 && i){
            //cout << i << " " << score << "\n";
            return score;
        }
        else{
            for(auto v : g[i]){
                if(v == par) continue;
                add = max(add, solve(v, a, i));
            }

            score += add;
            //cout << add << "\n";
            //cout << i << " " << score << "\n";
            return score;
        }

        return -1;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int b, vector<int>& a) {

        int n = 1 + edges.size();
        vector<int> t[n];
        vector<int> vp(n, -1);
        for(auto v : edges) t[v[0]].push_back(v[1]), t[v[1]].push_back(v[0]);
        g = t;

        store_par(0, 0, -1, vp);
        move_bob(b, 0, vp);
        int res = solve(0, a, -1);

        return res;
    }
};

