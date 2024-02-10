#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(int i, int j, int n, int m){

    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}

bool checkCycle(vector<vector<char>> &board, vector<vector<bool>> &vis, int r, int c, int i, int j, int len){

    int n = board.size();
    int m = board[0].size();

    bool res = false;

    if(i == r && j == c){
        if(len >= 4)
        return true;
        else if(len != 0)
        return false;
    }

    vis[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int x = dxdy[k][0];
        int y = dxdy[k][1];

        if(isValid(i+x, j+y, n, m) && board[r][c] == board[i+x][j+y] && !vis[i+x][j+y])
        res |= checkCycle(board, vis, r, c, i+x, j+y, len+1);
        else if(isValid(i+x, j+y, n, m) && i+x == r && j+y == c)
        res |= checkCycle(board, vis, r, c, i+x, j+y, len+1);

        if(res == true)
        return true;
    }

    return res;

}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool cycle = false;

    fr(i, n){
        fr(j, m){
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            bool nxt = checkCycle(board, vis, i, j, i, j, 0);
            cycle |= nxt;
            
            if(cycle == true)
                return true;
            
            vis.clear();
        }
    }

    return cycle;
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}