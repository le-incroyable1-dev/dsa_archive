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


void sol(){
    
}


vector<int> r;


int main(void){
    
    fast;

    vector<pair<int, int>> vp;
    int n;
    cin >> n;
    
    int reward;

    fr(i, n){
        int f, s;
        cin >> f >> s;
        vp.pb(mp(f, s));
        cin >> reward;
        r.pb(reward);
    }

    sort(all(vp));
    vector<int> dp(n, -1);
    int ans = 0;
    //int ans = helper(n, vp, dp, 0);
    cout << ans << endl;

    return 0;
}

// vector<int> r;

// int helper(int &n, vector<pair<int, int>> &vp, vector<int> &dp, int si){

//     int res = 0;

//     rep(i, si, n-1){
//         pair cur = vp[i];

//         if(dp[i] == -1){

//             int e = cur.second;
//             pair p = mp(e, INT_MAX);
//             int pos = upper_bound(vp.begin(), vp.end(), p) - vp.begin();

//             int next = 0;
//             if(pos >= n)
//             next = r[i];
//             else
//             next = r[i] + helper(n, vp, dp, pos);

//             res = max(res, next);
//             dp[i] = next;
//         }
//         else{
//             res = max(res, dp[i]);
//         }
//     }

//     return res;
// }


// int main(void){
    
//     fast;

//     vector<pair<int, int>> vp;
//     int n;
//     cin >> n;
    
//     int reward;

//     fr(i, n){
//         int f, s;
//         cin >> f >> s;
//         vp.pb(mp(f, s));
//         cin >> reward;
//         r.pb(reward);
//     }

//     sort(all(vp));
//     vector<int> dp(n, -1);
//     int ans = helper(n, vp, dp, 0);
//     cout << ans << endl;

//     return 0;
// }