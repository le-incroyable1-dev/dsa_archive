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

/*
There are n people numbered 1 . . . n who are looking for rides and need to be assigned to
n taxis also numbered 1 . . . n. There is also a cost matrix, where cost[i][j] denotes the
cost of letting person i ride taxi j. Each person needs to be assigned a taxi, and each taxi
must be assigned to exactly one person. What is the minimum total cost?
*/


//O(n* (2^n))
void assign(vector<vector<int>> cost, int n){

    int mx = pow(2, n) - 1;
    vector<int> dp(n, INT_MAX);

    //iterating over the mask, i.e. the "mask-th" person here
    rep(mask, 0, mx){

        //iterating over the n taxis
        fr(i, n){
            int num = (mask & mx);

            if((mask & (1 << i)) == 0){
                int nxt = (mask | (1 << i));
                dp[nxt] = min(dp[nxt], cost[num][i]);
            }
        }
    }

    cout << dp[mx] << endl;
    return;
}


int main(void){
    
    fast;
    
}
