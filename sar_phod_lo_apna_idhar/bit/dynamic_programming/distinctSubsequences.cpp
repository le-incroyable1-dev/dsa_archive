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


int lcs(string A, string B){
    
    ll n = A.size();
    ll m = B.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    fr(i, m)
    dp[i][0] = 0;
    fr(i, n)
    dp[0][i] = 0;

    rep(i, 1, m){
        rep(j, 1, n){
            int res1 = INT_MIN;
            
            if(A[j-1] == B[i-1])
            res1 = 1 + dp[i-1][j-1];

            dp[i][j] = max(res1, max(dp[i-1][j], dp[i][j-1]));
        }
    }

    return dp[m][n];
}

// case 1). if T[i] != S[j], then the solution would be to ignore the character S[j] 
// and align substring T[0..i] with S[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].

// case 2). if T[i] == S[j], then first we could adopt the solution in case 1), but also 
// we could match the characters T[i] and S[j] and align the rest of them (i.e. T[0..(i-1)] and S[0..(j-1)]. 
// As a result, dp[i][j] = dp[i][j-1] + d[i-1][j-1]

int numDistinct(string S, string T) {
    int sLen = S.length(), tLen = T.length();
    if (sLen < tLen) return 0;
    if (sLen == tLen) {
        if (S.compare(T) == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int path[tLen+1][sLen+1], i, j;
    
    for (i = 0; i <= sLen; ++i) {
        path[0][i] = 0;
    }
    for (j = 0; j <= tLen; ++j) {
        path[j][0] = 0;
    }
    
    for (i = 1; i <= tLen; ++i) {
        for (j = 1; j <= sLen; ++j) {
            if (T.at(i-1) == S.at(j-1)) {
                if (i != 1) {
                    path[i][j] = path[i][j-1] + path[i-1][j-1];
                } else {
                    path[i][j] = path[i][j-1] + 1;
                }
            } else {
                path[i][j] = path[i][j-1];
            }
        }
    }
    return path[tLen][sLen];
}

// unordered_set<string> s;

// void helper(string A, string B, int index, int &res){
//     if(index == A.length())
//     return;

//     int len = B.length();
//     if(lcs(A, B) == len)
//     s.insert(A);

//     string An = A;
//     A[index] = '~';

//     helper(A, B, index+1, res);
//     helper(An, B, index+1, res);

//     return;
// }



// int numDistinct(string A, string B) {

//     if(A.length() < B.length())
//     return 0;
//     else if(A.length() == B.length())
//     return A==B;

//     int res = 0;
//     //helper(A, B, 0, res);

//     //res = s.size();

//     return res;
// }
