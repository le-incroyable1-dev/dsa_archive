#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int func(vector<vector<int>> v, int x, int y){

    unordered_set<ld> s;

    for(auto p : v){
        ld x1 = (ld)p[0];
        ld y1 = (ld)p[1];

        ld slope = ((y1 - (ld)y)/(x1 - (ld)x));

        s.insert(slope);
    }

    int ans = (int)s.size();
    return ans;
}