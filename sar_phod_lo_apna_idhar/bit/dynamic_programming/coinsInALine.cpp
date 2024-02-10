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

int maxcoin_dp(vector<int> &A) {

    int n = A.size();

    if(n == 1)
    return A[0];
    else if(n == 2)
    return max(A[0], A[1]);

    vector<vector<int>> dp(n, vector<int>(n, 0));

    per(i, n-1, 0){
        rep(j, i, n-1){
            if(i == j){
                dp[i][j] = A[i];
                continue;
            }
            else if(j == i+1){
                dp[i][j] = max(A[i], A[j]);
                continue;
            }

            int sum = 0;
            rep(k, i, j)
            sum += A[k];

            dp[i][j] = sum - min(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}


int helper(vector<int> &A, int si, int ei, int sum){

    if(si == ei)
    return A[si];

    int nxt1 = helper(A, si+1, ei, sum-A[si]);
    int nxt2 = helper(A, si, ei-1, sum-A[ei]);

    // int sum = 0;
    // rep(i, si, ei)
    // sum += A[i];

    return sum - min(nxt1, nxt2);
}

int maxcoin(vector<int> &A) {

    int n = A.size();

    if(n == 1)
    return A[0];
    else if(n == 2)
    return max(A[0], A[1]);

    int chance = 0;
    int ans = 0;
    
    int sum = 0;
    rep(i, 0, n-1)
    sum += A[i];
    
    ans = helper(A, 0, n-1, sum);

    return ans;
}



void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}