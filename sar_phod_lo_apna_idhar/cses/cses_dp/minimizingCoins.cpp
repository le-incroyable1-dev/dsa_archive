#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef int ll;
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


void sol2(ll n, ll x, vi v){

    vector<vector<ll>> dp(n+1, vector<ll>(x+1, -1));

    rep(i, 0, x)
    dp[n][i] = INT_MAX;

    rep(i, 0, n)
    dp[i][0] = 0;

    per(i, n, 0){
        rep(j, 0, x){
            if(dp[i][j] == -1){
                ll s1 = INT_MAX;
                if(j - v[i] >= 0 && (dp[i][j-v[i]] != INT_MAX))
                s1 = 1 + dp[i][j-v[i]];

                ll s2 = dp[i+1][j];

                dp[i][j] = min(s1, s2);
            }
            else
            continue;
        }
    }

    if(dp[0][x] >= INT_MAX)
    cout << -1;
    else
    cout << dp[0][x];

    return;
}

// ll sol(ll n, ll x, vi v, int i){

//     if(x == 0)
//     return 0;

//     if(i == n)
//     return LLONG_MAX;

//     ll sum1 = LLONG_MAX;
//     if(x-v[i] >= 0)
//     sum1 = 1 + sol(n, x-v[i], v, i);

//     ll sum2 = sol(n, x, v, i+1);

//     ll res = min(sum1, sum2);
    
//     if(res == LLONG_MAX)
//     return -1;
//     else
//     return res;
// }



int main(void){
    
    //fast;

    ll n, x;
    cin >> n >> x;
    vi v;

    ll ele;
    fr(i, n){
        cin >> ele;
        v.pb(ele);
    }

    sort(all(v));
    reverse(all(v));

    //cout << sol(n , x, v, 0);
    sol2(n, x, v);
}