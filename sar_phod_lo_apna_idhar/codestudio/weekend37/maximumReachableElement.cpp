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


// int helper(int x, int y, vector<vector<int>> &grid, int X, int Y){

//     int n = grid.size();
//     int m = grid[0].size();

//     if(x == X-n || Y == Y-m)
//     return INT_MIN;

//     if(x == 0 && y == 0)
//     return INT_MIN;

//     int i = X - x;
//     int j = Y - y;


//     int rmax = helper(x, y-1, grid, X, Y);
//     int dmax = helper(x-1, y, grid, X, Y);


// }

vector<int> maximumReachableElement(vector<vector<int>>&grid, vector<vector<int>>&query) {
	
    int n = grid.size();
    int m = grid[0].size();
    int q = query.size();
    vector<int> ans;
    vector<vector<int>> mv(n, vector<int>(m, 0));

    rep(i, 0, n-1){
        rep(j, 0, m-1){
            mv[i][j] = grid[i][j];

            if(i-1 >= 0)
            mv[i][j] = max(mv[i][j], mv[i-1][j]);
            if(j-1 >= 0)
            mv[i][j] = max(mv[i][j], mv[i][j-1]);
            if(i-1 >= 0 && j - 1 >= 0)
            mv[i][j] = max(mv[i][j], mv[i-1][j-1]);
                       
        }
    }

    fr(i, q){
        int x = query[i][0];
        int y = query[i][1];

        ans.pb(mv[x-1][y-1]);
    }

    return ans;

}