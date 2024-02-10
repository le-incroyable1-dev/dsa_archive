#include <bits/stdc++.h>
using namespace std;


int dxdy[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
//use to cover all directions


//incomplete
bool checkPath(int r, int c, int nxt, string &target, vector<vector<char>> &board){

    int n = board.size();
    int m = board[0].size();

    if(r >= n || c >= m)
        return false;
    
    if(nxt >= target.length())
        return true;
    
    bool res = false;


    if(c+1 < m && board[r][c+1] == target[nxt])
        res |= checkPath(r, c+1, nxt+1, target, board);
    if(r+1 < n && board[r+1][c] == target[nxt])
        res |= checkPath(r+1, c, nxt+1, target, board);
    if(c+1 < m && r+1 < n && board[r+1][c+1] == target[nxt])
        res |= checkPath(r+1, c+1, nxt+1, target, board);
    if(c < m && r-1 >= 0 && board[r-1][c] == target[nxt])
        res |= checkPath(r-1, c, nxt+1, target, board);
    if(c+1 < m && r-1 >= 0 && board[r-1][c+1] == target[nxt])
        res |= checkPath(r-1, c+1, nxt+1, target, board);
    if(c+1 < m && r-1 >= 0 && board[r-1][c+1] == target[nxt])
        res |= checkPath(r-1, c+1, nxt+1, target, board);
    if(c+1 < m && r-1 >= 0 && board[r-1][c+1] == target[nxt])
        res |= checkPath(r-1, c+1, nxt+1, target, board);
    if(c+1 < m && r-1 >= 0 && board[r-1][c+1] == target[nxt])
        res |= checkPath(r-1, c+1, nxt+1, target, board);
    
    //bool res = (b1 | (b2 | b3));
    return res;
        
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 'C')
                vp.push_back(make_pair(i, j));
        }
    }
    
    string target = "CODINGNINJA";
    
    for(auto p : vp){
        int r = p.first;
        int c = p.second;
        
        if(checkPath(r, c, 1, target, board))
            return true;
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}