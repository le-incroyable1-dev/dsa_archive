#include<bits/stdc++.h>
using namespace std;
#define mod 1003
#define mod2 1003
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
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


//CHECK LIST

int findWays_dp(string &exp){
    int n = exp.length();

    int dp[n][n][2];
    fr(i, n)
    fr(j, n)
    fr(k, 2)
    dp[i][j][k] = 0;

    fr(i, n){
        fr(j, n){

        }
    }
}

int findWays(string &exp, int i, int j, int isTrue) {

    // Corner Cases.
    if (i > j) {
        return 0;
    }

    // If the length of expression is 1, we need to evaluate its value.
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T' ? 1 : 0;
        } else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }

    long long int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
    
        // The number of ways expression left to 'K' will be true.
        long long int leftTrue = (findWays(exp, i, k - 1, 1)) % mod;

        // The number of ways expression left to 'K' will be false.
        long long int leftFalse = (findWays(exp, i, k - 1, 0)) % mod;

        // The number of ways expression right to 'K' will be true.
        long long int rightTrue = (findWays(exp, k + 1, j, 1)) % mod;

        // The number of ways expression right to 'K' will be false.
        long long int rightFalse = (findWays(exp, k + 1, j, 0)) % mod;

        if (exp[k] == '|') {
            // T | T = T, T | F = T, F | T = T , F | F = F.
            if (isTrue) {
                ans += leftTrue * rightTrue + leftTrue *

                rightFalse + leftFalse * rightTrue;
                ans = ans % mod;
            } else {
                ans += leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else if (exp[k] == '&') {
            // T & T = T, T & F = F, F & T = F , F | F = F.
            if (isTrue) {
                ans += leftTrue * rightTrue;
                ans = ans % mod;

            } else {
                ans += leftTrue * rightFalse + leftFalse *

                rightTrue + leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else {
            // T ^ T = F, T ^ F = T, F ^ T = T , F ^ F = F.
            if (isTrue) {
                ans += leftTrue * rightFalse + leftFalse *

                rightTrue;
                ans = ans % mod;
            } else {
                ans += leftTrue * rightTrue + leftFalse *

                rightFalse;
                ans = ans % mod;
            }
        }
    }
    return ans;
}

// string evaluate(char f, char op, char s){

//     if(op == '&'){
//         if(f == 'F' || s == 'F')
//         return "F";
//         else
//         return "T";
//     }
//     else if(op == '|'){
//         if(f == 'T' || s == 'T')
//         return "T";
//         else
//         return "F";
//     }
//     else{
//         if(f == s)
//         return "F";
//         else
//         return "T";
//     }
// }

// //F|T^T&F


// void helper(string A, int &ans){

//     int n = A.length();

//     if(n == 1){
//         ans += (A == "T");
//         return;
//     }
//     else if(n == 3){
//         char f = A[0];
//         char op = A[1];
//         char s = A[2];

//         ans += (evaluate(f,op,s) == "T");
//         return;
//     }

//     int lim = (n-3)/2;
//     rep(k, 0, lim){
//         string cur = A;
//         string p1 = cur.substr(0, 2*k);
//         string p2 = cur.substr(2*k + 3);

//         char f = A[2*k];
//         char op = A[2*k + 1];
//         char s = A[2*k + 2];

//         string next = p1 + evaluate(f, op, s) + p2;
//         helper(next, ans);
//     }

//     return;

// }

int cnttrue(string A) {

    int n = A.length();
    //memo = vector<vector<vector<long long int>>> (n, vector<vector<long long int>>(n, vector<long long int>(2, -1)));
    return findWays(A, 0, n-1, 1);

    // if(n%2 != 1)
    // return 0;

    // if(n == 1)
    // return A == "T";
    // else if(n == 3){
    //     char f = A[0];
    //     char op = A[1];
    //     char s = A[2];

    //     return (evaluate(f,op,s) == "T");
    // }

    // int ans = 0;
    // helper(A, ans);

    // return ans;
}


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}