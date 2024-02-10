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



int solve_dp(vector<vector<int> > &A) {

    ll n = A.size();
    int min_cost;

    vector<vector<int>> dp(n, vector<int>(3, INT_MAX));


    fr(i, 3)
    dp[0][i] = A[0][i];

    rep(i, 1, n-1){
        rep(j, 0, 2){
            for(auto color : {0, 1, 2}){
                if(color != j){
                    dp[i][j] = min(dp[i][j], dp[i-1][color] + A[i][j]);
                }
            }
        }
    }

    min_cost = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    return min_cost;
}


void helper(vector<vector<int>> &A, int cur_cost, int &min_cost, int prev, ll n){

    if(n == 0){
        min_cost = (min_cost > cur_cost ? cur_cost : min_cost);
        return;
    }

    if(min_cost <= cur_cost)
    return;

    for(auto i : {0, 1, 2}){
        if(i != prev){
            helper(A, cur_cost + A[(ll)A.size()-n][i], min_cost, (int)i, n-(ll)1);
        }
    }

    return;
}

int solve(vector<vector<int> > &A) {

    ll n = A.size();
    int min_cost = INT_MAX;

    helper(A, 0, min_cost, -1, n);

    return min_cost;
}



void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}