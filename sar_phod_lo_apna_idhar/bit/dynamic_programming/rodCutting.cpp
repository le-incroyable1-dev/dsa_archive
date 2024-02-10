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


void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j, vector<int> p) {
    if (i + 1 == j) return ;
    for (int k = i + 1; k < j; k++) {
        if (dp[i][k] + dp[k][j] + p[j] - p[i] == dp[i][j]) {
            ans.push_back(p[k]);
            getAns(ans, dp, i, k, p);
            getAns(ans, dp, k, j, p);
            return ;
        }
    }
    return ;
}


vector<int> rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for (int b: B) p.push_back(b);
    p.push_back(A);
    sort(p.begin(), p.end());
    
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            dp[i][i+l-1] = INT_MAX;
            for (int k = i + 1; k < i + l - 1; k++)
                dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][k] + dp[k][i+l-1] + p[i+l-1] - p[i]);
        }
                
    }
    
    vector<int> ans;
    getAns(ans, dp, 0, n - 1, p);
    return ans;
    
}




void sol(){
    
}



int main(void){
    
    fast;
    int n = 6;
    vector<int> A = {1,2,5};

    for(auto val : rodCut(n, A))
    cout << val << " ";

    return 0;
}