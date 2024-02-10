#include <bits/stdc++.h>
using namespace std;


//adds the nodes of "graph" to "topo" in reverse topological order
//reverse "topo" to get the nodes topologically sorted
void topoSort(vector<vector<int>> &graph, int start, vector<int> &vis, vector<int> &topo){
    
    vis[start] = 1;
    //mark current node as visited

    int n = graph.size();

    for(int i = 0; i < n; ++i){
        if(!vis[i] && graph[start][i] == 1){
            topoSort(graph, i, vis, topo);
            //if a node is not visited and is the successor
            //of current node process it first and add it to topo list
        }
    }


    topo.push_back(start);
    //after processing all successors and adding them to the topo list
    //add the current node to the list as well

    return;
}