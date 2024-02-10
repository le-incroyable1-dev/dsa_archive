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


void sol(int &paths, int i, int j, int n, vector<string> mat){

    if(i == n-1 && j == n-1)
    paths += 1;

    if(i < n-1 && mat[i+1][j] != '*')
    sol(paths, i+1, j, n, mat);

    if(j < n-1 && mat[i][j+1] != '*')
    sol(paths, i, j+1, n, mat);


    return;
}

void sol(vector<string> &path){
    
    ll n = path.size();
    int dp[n][n];

    fr(i, n){
        fr(j, n)
        dp[i][j] = 0;
    }
    
    dp[0][0] = 1;
    //reaching at the end signifies there was one path possible

    fr(i, n){
        fr(j, n){
            if(i-1 >= 0){
                if(path[n-1-i+1][n-1-j] != '*')
                dp[i][j] += dp[i-1][j]%mod;
            }

            if(j-1 >= 0){
                if(path[n-1-i][n-1-j+1] != '*')
                dp[i][j] += dp[i][j-1]%mod;
            }

            dp[i][j] = dp[i][j]%mod;
        }
    }

    cout << dp[n-1][n-1];

    return;
}



int main(void){
    
    fast;

    int n;
    cin >> n;

    vector<string> mat;
    string s;

    fr(i, n){
        cin >> s;
        mat.pb(s);
    }

    if(mat[0][0] == '*'){
        cout << 0;
        return 0;
    }

    //int paths = 0;
    sol(mat);
    //cout << paths << endl;  

    return 0; 
}