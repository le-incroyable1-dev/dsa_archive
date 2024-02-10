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

int solve(vector<vector<int> > &A) {

    int n = A.size();
    if(n == 0)
    return 0;
    
    int m = A[0].size();
    if(m == 0)
    return 0;
    
    int dp[n][n][m][m];

    fr(i, n)
    fr(j, n)
    fr(k, m)
    fr(l, m)
    dp[i][j][k][l] = 0;

    int count = 0;

    rep(i, 0, n-1){
        rep(j, i, n-1){
            rep(k, 0, m-1){
                rep(l, k, m-1){
                    int extra = 0;

                    rep(row, i, j)
                    extra += A[row][l];
                    rep(col, k, l-1)
                    extra += A[j][col];

                    if(j > i && l > k && j-1 >= 0 && l-1 >= 0)
                    dp[i][j][k][l] = dp[i][j-1][k][l-1] + extra;
                    else
                    dp[i][j][k][l] = extra;

                    if(dp[i][j][k][l] == 0)
                    count++;
                }
            }
        }
    }

    return count;
}


void sol(){
    
}



int main(void){
    
    fast;

    // test(t){
    //     sol();
    // }

    vector<vector<int>> A = {{-8,5,7},{3,7,-8},{5,-8,9}};
    cout << solve(A) << endl;
}