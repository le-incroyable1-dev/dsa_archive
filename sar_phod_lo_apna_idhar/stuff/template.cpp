#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:

    bool compare(vector<int> &v1, vector<int> &v2){
        

    }

    int numberOfPairs(vector<vector<int>>& p) {

        for(auto &v : p) v[1] *= -1; //flip y axis
        sort(p.begin(), p.end());
        int n = p.size();
        unordered_map<ll, ll> xm, ym;
        ll res = 0;

        for(int i = 0; i  < n - 1; ++i){
            int x1 = p[i][0]; int y1 = p[i][1];
            xm[x1]++; ym[y1]++;

            int x2 = p[i+1][0]; int y2 = p[i+1][1];
            if(x2 > x1 && y2 > y1) ++res;
            res += xm[x2]; res += ym[y2];
        }

        return res;
    }
};


int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<int>> p = {{6,2}, {4,4}, {2,6}};
    Solution sol; sol.numberOfPairs(p);
   
    return 0;
}
