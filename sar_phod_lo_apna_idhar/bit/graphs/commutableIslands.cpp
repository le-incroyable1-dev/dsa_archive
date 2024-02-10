#include <bits/stdc++.h>
using namespace std;


//Kruskal's ALgorithm
//Uses disjoint set (union find)

int parent(vector<int> &p, int x){
    while(p[x] != x){
        p[x] = p[p[x]];
        x = p[x];
    }

    return x;
}

bool compare(vector<int> &v1, vector<int> &v2){
    return (v1[2] < v2[2]);
}

int solve(int A, vector<vector<int> > &B) {
    int m = B.size();
    sort(B.begin(), B.end(), compare);

    vector<int> p(A+1, -1);
    for(int i = 0; i < A+1; ++i)
    p[i] = i;

    int cost = 0;
    for(int i = 0; i < m; ++i){
        vector<int> v = B[i];

        int src = v[0];
        int dest = v[1];

        int psrc = parent(p, src);
        int pdest = parent(p, dest);

        if(psrc != pdest){
            cost += v[2];
            src = parent(p, src);
            dest = parent(p, dest);
            p[src] = dest;
        }
    }

    return cost;
    
}

int main(){
    vector<vector<int>> B = {
        {1,2,1},
        {2,3,4},
        {1,4,3},
        {4,3,2},
        {1,3,10}
    };

    cout << solve(4,B);
}