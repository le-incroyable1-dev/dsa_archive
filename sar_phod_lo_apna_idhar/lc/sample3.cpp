#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
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


class Solution {
public:

    bool helper(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<vector<bool>> &fill){


        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m)
        return false;
        
        if(vis[i][j]) return fill[i][j];
        
        vis[i][j] = true;

        if(i == n-1 && j == m-1){
            return fill[i][j] = true;
        }

        bool res = false;

        bool right = helper(i, j+1, grid, vis, fill);
        bool down = helper(i+1, j, grid, vis, fill);

        if(grid[i][j] == 0) return false;

        res |= right;
        res |= down;

        fill[i][j] = res;
        return res;

    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> fill(n, vector<bool>(m, false));

        bool res = helper(0, 0, grid, vis, fill);
    

        if(!res) return true;

        int i = n-1;
        int j = m-1;

        while(i >= 0 && j >= 0){
            int si = i-1;
            int sj = j-1;

            if(si < 0 || sj < 0) break;

            int count = 0;

            if(fill[si][sj]) count++;

            for(int row = si+1; row < n; ++row){
                if(fill[row][sj]) count++;
            }
            for(int col = sj+1; col < m; ++col){
                if(fill[si][col]) count++;
            }

            if(count <= 1)
            return true;

            i = si;
            j = sj;
        }

        return false;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {{1,1,1}, {1,0,0}, {1,1,1}};
    cout << sol.isPossibleToCutPath(grid);

    return 0;
}