#include <bits/stdc++.h>
using namespace std;

//all directions
int dxdy2[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {0,-1}};

//checking validity of a point within matrix constraints
bool isValid(int i, int j, int n, int m){
    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}
/*
[
  [0, 0, 1, 0, 0, 0, 0, 0]
  [1, 1, 1, 1, 1, 1, 1, 0]
]
*/
int maxLen(vector<vector<int>> &mat, int i, int j, vector<vector<bool>> &vis){
    
    int n = mat.size();
    int m = mat[0].size();
    
    int len = 1;

    vis[i][j] = true;
    
    for(int k = 0; k < 8; ++k){
        int x = i + dxdy2[k][0];
        int y = j + dxdy2[k][1];
        
        if(isValid(x, y, n, m) && mat[x][y] == 1 && !vis[x][y]){
            //len = max(len, 1 + maxLen(mat, x, y));
            int nxt = maxLen(mat, x, y, vis);
            len += nxt;
        }
    }
    
    return len;
}

/*
[
  [0, 0, 1, 0, 0, 0, 0, 0]
  [1, 1, 1, 1, 1, 1, 1, 0]
]
*/
int solve(vector<vector<int> > &mat) {
    
    int n = mat.size();
    int m = mat[0].size();
    
    int ans = 0;

    vector<vector<bool>> vis(n, vector<bool>(m ,false));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == 1 && !vis[i][j]){
                
                ans = max(ans, maxLen(mat, i, j, vis));
            }
        }
    }
    
    return ans;
    
}


/*
 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
*/
int main(){

    vector<vector<int>> mat = {
       {0,0,1,0,0,0,0,0},
       {1,1,1,1,1,1,1,0}
    };

    cout << solve(mat) << endl;

    return 0;
}