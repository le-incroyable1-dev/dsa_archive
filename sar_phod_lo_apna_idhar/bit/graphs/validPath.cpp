#include <bits/stdc++.h>
using namespace std;

int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};
int dxdy1[4][2] = {{1,-1}, {-1, 1}, {1, 1}, {-1, -1}};
int dxdy2[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


bool isValid(int i, int j, int n, int m){
    if(i >= 0 && i <= n && j >= 0 && j <= m)
    return true;
    else
    return false;
}



bool dfs(vector<vector<bool>> &vis, vector<vector<bool>> &oc, int x, int y, int a, int b){

    if(vis[x][y] || oc[x][y])
    return false;

    vis[x][y] = true;
    bool res = false;

    if(x == a && y == b)
    return true;

    for(int k = 0; k < 8; ++k){
        int x1 = x + dxdy2[k][0];
        int y1 = y + dxdy2[k][1];

        if(isValid(x1, y1, a, b) && !vis[x1][y1] && !oc[x1][y1])
        res |= dfs(vis, oc, x1, y1, a, b);

        if(res)
        break;
    }

    return res;
}


string solve(int x , int y, int m, int r, vector<int> &xv, vector<int> &yv) {

    vector<vector<bool>> vis(x+1, vector<bool>(y+1, false));
    vector<vector<bool>> oc(x+1, vector<bool>(y+1, false));

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            for(int k=0;k<xv.size();k++)
            {
                if(((xv[k]-i)*(xv[k]-i) + (yv[k]-j)*(yv[k]-j)) <= r*r)
                {
                    oc[i][j]=true;
                    break;
                }
            }
        }
    }
   

    if(dfs(vis, oc, 0, 0, x, y))
    return "YES";
    else
    return "NO";

}


int main(){

    vector<int> a  = {2};
    vector<int> b = {3};

    cout << solve(2, 3, 1, 1, a, b);
    return 0;
}

