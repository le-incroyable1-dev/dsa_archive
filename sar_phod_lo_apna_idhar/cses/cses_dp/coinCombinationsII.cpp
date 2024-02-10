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


void sol2(int n, int x, vi &v){

    int dp[n][x+1];
    fr(i, n){
        fr(j, x+1)
        dp[i][j] = 0;
    }

    fr(i, n)
    dp[i][0] = 1;

    fr(i, x+1){

        if(i == 0){
            dp[0][i] = 1;
            continue;
        }

        int val = (int)i;
        if(val%v[n-1] == 0)
        dp[0][i] = 1;
        else
        dp[0][i] = 0;
    }

    fr(i, n){
        fr(j, x+1){
            if(i != 0 && j != 0){
                dp[i][j] += (dp[i-1][j]%mod);

                if(j - v[n-(i+1)] >= 0)
                dp[i][j] += (dp[i][j-v[n-(1+i)]]%mod);

                dp[i][j] = (dp[i][j]%mod);
            }
        }
    }

    cout << dp[n-1][x]%mod;

    return;
}

int sol(int n , int x, vi &v, int ei){
    
    if(ei < 0)
    return 0;
    else if(ei == 0){
        // if(x-v[0] >= 0)
        // return (sol(n, x-v[0], v, ei)%mod);
        if(x%v[0] == 0)
        return 1;
        else
        return 0;
    }

    if(x == 0)
    return 1;

    int val1 = 0;
    int val2 = 0;

    val1 = sol(n, x, v, ei-1)%mod;

    if(x-v[ei] >= 0)
    val2 = sol(n, x-v[ei], v, ei)%mod;

    int res = (val1 + val2)%mod;
    return res%mod;
}



int main(void){
    
    fast;

    int n, x;
    cin >> n >> x;
    vi v;

    int ele;
    fr(i, n){
        cin >> ele;
        v.pb(ele);
    }

    // n = 3;
    // x = 9;
    // v = {2, 3, 5};

    sort(all(v));
    //reverse(all(v));

    //cout << sol(n, x, v, n-1);
    sol2(n, x, v);

    return 0;
}