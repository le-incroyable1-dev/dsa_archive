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



//bottom up, pure dp, verified
void sol(vi v, ll n){

    
    ll sums[n][n];

    rep(i, 0, n-1)
    sums[i][i] = v[i];

    rep(l, 0, n-1){
        //um += v[l];
        ll rsum = 0;
        rep(r, l+1, n-1){
            rsum += v[r];
            sums[l][r] = v[l] + rsum;
        }
    }

    ll dp[n][n];

    rep(i, 0, n-1)
    dp[i][i] = v[i];

    ll sum = 0;

    per(l, n-2, 0){
        //int rc;
        //sum += v[l];
        rep(r, l+1, n-1){

            if(r-1 == l){
                //sum += v[r];
                dp[l][r] = max(v[l], v[r]);
            }
            else{
                // sum = 0;
                // rep(i, l, r)
                // sum += v[i];
                
                //sum += v[r];
                sum = sums[l][r];
                dp[l][r] = sum - min(dp[l+1][r], dp[l][r-1]);
            }
        }
        
    }

    cout << dp[0][n-1];
    return;    
}

//recursive
int sol(vi v, int l, int r, bool mychance){
    
    if(l == r){
        if(mychance)
        return v[l];
        else
        return 0;
    }

    int val1 = v[l] + sol(v, l+1, r, false);
    int val2 = v[r] + sol(v, l, r-1, false);

    if(mychance)
    return max(val1, val2);
    else{
        if(val1 > val2)
        return sol(v, l+1, r, true);
        else
        return sol(v, l, r-1, true);
    }
}

// void sol(vi v, int n){

//     vector<vector<vector<int>>> dp;
//     vector<vector<int>> s1(n, vector<int>(n, 0)); //my chance
//     vector<vector<int>> s2(n, vector<int>(n, 0));
//     dp.pb(s1);
//     dp.pb(s2);

//     fr(i, n){
//         dp[0][i][i] = v[i];
//         dp[1][i][i] = 0;
//     }

//     per(l, n-1, 0){
//         rep(r, 0, n-1){

//             if(l >= r)
//             continue;

//             int v1 = dp[1][l+1][r];
//             int v2 = dp[1][l][r-1];

//             dp[0][l][r] = max(v1, v2);

//             if(v1 > v2)
//             dp[1][l][r] = dp[0][l+1][r];
//             else
//             dp[1][l][r] = dp[0][l][r-1];
//         }
//     }

//     cout << dp[0][0][n-1];

// }


int main(void){
    
    fast;

    int n;
    cin >> n;

    int ele;
    vi v;
    fr(i, n){
        cin >> ele;
        v.pb(ele);
    }

    //cout << sol(v, 0, n-1, true);
    sol(v, n);
    return 0;
}