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

// BWWWWBBWWBWBWWBBBBBWBWWBBBWWWWBBBW
// 28


int helper(string &s, int n, int k, vector<vector<int>> &dp){

    if(dp[n][k] != -1)
    return dp[n][k];
    
    if(k > n){
        dp[n][k] = -1;
        return -1;
    }

    if(n == 0){
        dp[n][k] = 0;
        return 0;
    }

    int sz = s.length();
    if(k == 1){
        int wc = 0;
        int bc = 0;

        rep(i, sz-n, sz-1){
            if(s[i] == 'W')
            wc++;
            else
            bc++;
        }

        int res = wc*bc;
        dp[n][k] = res;
        return res;
    }

    int min_cost = INT_MAX;
    int bc = 0;
    int wc = 0;

    rep(i, sz-n, sz-(k-1)-1){

        if(s[i] == 'B')
        bc++;
        else
        wc++;

        int cur_cost = bc*wc;
        int rem = n - (bc + wc);

        int next = helper(s, rem, k-1, dp);
        cur_cost += next;
        if(cur_cost < min_cost)
        min_cost = cur_cost;
    }

    dp[n][k] = min_cost;
    return min_cost;

}

int arrange(string A, int B) {

    int n = A.length();
    if(n < B)
    return -1;
    else if(n == B)
    return 0;

    vector<vector<int>> dp(n+1, vector<int>(B+1,-1));

    return helper(A, n, B, dp);
}



void sol(){
    
}



int main(void){
    
    fast;

    string A = "BWWWWBBWWBWBWWBBBBBWBWWBBBWWWWBBBW"; 
    //cin >> A;
    int B = 28;
    //cin >> B;

    cout << arrange(A, B) << endl;

    return 0;
}