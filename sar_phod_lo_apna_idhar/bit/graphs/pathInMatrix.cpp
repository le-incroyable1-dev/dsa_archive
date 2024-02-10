#include <bits/stdc++.h>
using namespace std;


//checking validity of a point within matrix constraints
bool isValid(int i, int j, int n, int m){
    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}

//vertical and horizontal
int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

bool helper(vector<vector<int>> &mat, vector<vector<bool>> &vis, int i, int j){

    int n = mat.size();
    if(mat[i][j] == 2)
    return true;
    vis[i][j] = true;

    bool res = false;

    for(int k = 0; k < 4; ++k){
        int x = i + dxdy[k][0];
        int y = j + dxdy[k][1];

        if(isValid(x, y, n, n)){
            if(mat[x][y] != 0 && !vis[x][y]){
                bool cur = helper(mat, vis, x, y);
                res |= cur;
            }

        }
        
        if(res)
        return true;
    }

    return res;

}

int checkPath(vector<vector<int> > &mat) {
    int n = mat.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    bool ans;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(mat[i][j] == 1 && !vis[i][j]){
                ans = helper(mat, vis, i, j);
            }
        }
    }

    if(ans)
    return 1;
    else
    return 0;
}

int main(){
    vector<vector<int>> v = {
        {1,3},
        {3,2}
    };

    cout << checkPath(v);
}