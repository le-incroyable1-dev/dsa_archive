#include <bits/stdc++.h>
using namespace std;


void dfs(int s, vector<int> *adj, bool *visited) {
    if (visited[s]) return;
    visited[s] = true;

    cout << s << " "; 
    // process node s
    for (auto u: adj[s]) {
        //cout << u << " ";
        dfs(u, adj, visited);
    }

    return;
}

void bfs(vector<int> *adj, int n, int x){

    cout << endl;

    queue<int> q;
    bool vis[n];
    for(int i = 0; i < n; ++i)
    vis[i] = false;

    int dist[n];
    for(int i = 0; i < n; ++i)
    dist[i] = 0;

    q.push(x);
    dist[x] = 0;
    vis[x] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << "," << dist[cur] << "__"; 

        for(auto u : adj[cur]){
            if(vis[u])
            continue;
            else{
                vis[u] = true;
                q.push(u);
                dist[u] = dist[cur]+1;
                //cout << u << " ";
            }
        }
    }

    return;
}

void bellmanFord(){
    
}

int main(){

    int n;
    cin >> n;

    //adjacency list
    vector<int> adj[n];
    
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);

    bool visited[n];
    for(int i = 0; i < n; ++i)
    visited[i] = false;

    
    
    return 0;
}