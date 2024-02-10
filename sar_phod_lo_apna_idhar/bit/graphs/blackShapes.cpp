#include <bits/stdc++.h>
using namespace std;

int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(int i, int j, int n, int m){

    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}

void search(vector<string> &A, int i, int j){
    
    A[i][j] = 'M';
    int n = A.size();
    int m = A[0].length();
        
    for(int k = 0; k < 4; ++k){
        int x = i + dxdy[k][0];
        int y = j + dxdy[k][1];
        
        if(isValid(x,y,n,m) && A[x][y] == 'X')
        search(A, x, y);
    }
    
    return;
}


int black(vector<string> &A) {
    
    int n = A.size();
    int m = A[0].length();
    
    //vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    int res = 0;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(A[i][j] == 'X'){
                res++;
                search(A, i, j);
            }
        }
    }

    return res;
    
}

int main()
{
    
    vector<string> A = {
        "OOOXOOO", 
        "OOXXOXO", 
        "OXOOOXO"
    };
    
    cout << black(A);
}