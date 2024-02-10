#include <bits/stdc++.h>
using namespace std;

#define N 101


int snakeLadder(vector<vector<int> > &l, vector<vector<int> > &s) {

    unordered_map<int, int> go;
    int n = l.size();
    int m = s.size();

    for(int i = 0; i < n; ++i)
    go.insert(make_pair(l[i][0], l[i][1]));
    for(int i = 0; i < m; ++i)
    go.insert(make_pair(s[i][0], s[i][1]));

    vector<bool> vis(N, false);
    queue<pair<int, int>> q;
    q.push({1, 0}); 
    vis[0] = true;
    vis[1] = true;

    int moves = -1;

    while(!q.empty()){

        pair<int, int> p = q.front(); q.pop();
        int cur = p.first;
        int rolls = p.second;

        vis[cur] = true;

        if(cur == 100){
            moves = rolls;
            return moves;
        }

        for(int j = 1; j <= 6 && cur + j <= 100; j++){
            if(go[cur+j] && !vis[go[cur+j]] && !vis[cur+j]){
                q.push({go[cur+j], rolls+1});
                vis[go[cur+j]] = true;
                vis[cur+j] = true;
            }
            else if(!vis[cur+j]){
                q.push({cur+j, rolls+1});
                vis[cur+j] = true;
            }
        }

    }

    return moves;

}


int main(){

    vector<vector<int>> l = {
        {32,62}, 
        {42, 68},
        {12, 98}
    };

    vector<vector<int>> s = 
    {
        {95, 13},
        {97, 25},
        {93, 37},
        {79, 27},
        {75, 19},
        {49, 47},
        {67, 17}
    };

    cout << snakeLadder(l, s);

    return 0;
}

