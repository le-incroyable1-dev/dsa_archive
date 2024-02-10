#include <bits/stdc++.h>
using namespace std;

stack<int> st;


void dfs2(vector<vector<int>> &g, vector<bool> &vis, int s){

    //st.push(s);

    vis[s] = true;
    int n = g.size();

    int res = 0;

    for(int i = 0; i < n; ++i){
        if(g[s][i] && !vis[i])
        dfs2(g, vis, i);
    }

    return;
}


void dfs(vector<vector<int>> &g, vector<bool> &vis, int s){

    st.push(s);

    vis[s] = true;
    int n = g.size();

    //int res = 0;

    for(int i = 0; i < n; ++i){
        if(g[s][i] && !vis[i])
        dfs(g, vis, i);
    }

    return;
}

int solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> g(n+1, vector<int>(n+1, 0));
    //set<int> s;

    for(int i = 0; i < n ; ++i){

        if(A[i]-1 == i)
        continue;

        g[i][A[i]-1] = 1;
        //g[A[i-1]][i]  = 1;

        //g[A[i]].push_back(i);
    }

    vector<bool> vis(n+1, false);
    //vis[0] = true;

    int i = 0;
    int ans = -1;

    while(i < n){
        while(vis[i])
        ++i;

        if(i == n)
        break;


        dfs(g, vis, i);
    }

    for(int i = 0; i < n+1; ++i)
    vis[i] = false;

    while(!st.empty()){

        int cur = st.top();
        if(vis[cur]){
            st.pop();
            continue;
        }

        st.pop();
        //vis[cur] = true;

        dfs2(g, vis, cur);
        ans++;
    }

    return ans;
}


int main(){
    vector<int> A = {1,2,1,2};
    cout << solve(A) << endl;
}