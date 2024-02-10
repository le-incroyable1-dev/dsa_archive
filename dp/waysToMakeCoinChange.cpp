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
#define vi vector< int >
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
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int func(int index, int target ,int *coins){
    if(index == 0){
        if(target %coins[0] == 0){
            return 1;
        }
        return 0;
    }

    if(target == 0)
    return 1;
    
    int notTake = func(index-1,target,coins);
    int take = 0;
    if(coins[index] <= target){
        take = func(index,target - coins[index],coins);    
    }
    return (take + notTake);
    

}

int dpHelper(int index, int target, int *coins){

    int n = index+1;
    int dp[n][target+1] = {0};

    fr(i, n+1)
    dp[i][0] = 1;

    rep(i, 1, target)
    dp[0][i] = (target%coins[0] == 0 ? 1 : 0);

    rep(i, 1, n-1){
        rep(j, 1, target){
            dp[i][j] += dp[i-1][j];

            if(coins[i] <= j)
            dp[i][j] += dp[i][j-coins[i]];
        }
    }

    return dp[n-1][target];
}

int countWaysToMakeChange(int* coins,int n, int amount) {

    return dpHelper(n-1, amount, coins);
    //return func(n - 1, amount,coins);
}