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
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


string findWinner(int n, int x, int y){

    int *dp = new int[n];
    fr(i, n)
    dp[i] = 0;

    dp[0] = 1;
    //if there is only one coin beerus wins
    //index i -> i+1 coins and beerus plays first

    int i = 1;
    while(i < n){
        int v1 = dp[i-1];
        int v2 = 0;
        int v3 = 0;

        if(i-x >= 0)
        v2 = dp[i-x];
        if(i-y >= 0)
        v3 = dp[i-y];

        v1 ^= 1;
        v2 ^= 1;
        v3 ^= 1;
        //if in any one case the value of vi is zero, then the xor will give 1
        //and res will result in 1, hence indicating that beerus can win
        int res = max(v1, max(v2, v3));
        dp[i] = res;

        ++i;
    }

    if(dp[n-1])
    return "Beerus";
    else
    return "Whis";
}

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}