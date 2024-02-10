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



int maxProfit2(const vector<int> &A) {

    int n = A.size();
    int b1 = INT_MAX;
    int b2 = INT_MAX;
    int s1 = 0;
    int s2 = 0;
    fr(i, n){
        b1 = min(b1, A[i]);
        s1 = max(s1, A[i] - b1);

        b2 = min(b2, A[i] - s1);
        s2 = max(s2, A[i] - b2);
    }

    return max(s1, s2);
}


void helper(int si, const vector<int> &A, int cur_profit, int &max_profit, int tr, vector<vector<vector<int>>> &dp){
    
    int n = A.size();
    
    //cout << cur_profit << endl;

    if(tr == 0 || si >= n){
        if(cur_profit > max_profit)
        max_profit = cur_profit;
        
        dp[si][cur_profit][tr] = max_profit;
        return;
    }

    rep(i, si+1, n-1){
        if(A[i] > A[si]){
            if(i+1 <= n && dp[i+1][cur_profit + A[i] - A[si]][tr-1] == -1)
            helper(i+1, A, cur_profit + A[i] - A[si], max_profit, tr-1, dp);
        }
    }

    if(dp[si+1][cur_profit][tr] == -1)
    helper(si+1, A, cur_profit, max_profit, tr, dp);

    return;
}


int maxProfit(const vector<int> &A) {
    int max_profit = INT_MIN;
    int n = A.size();
    int mx = *max_element(all(A)) - *min_element(all(A));
    mx *= 2;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(mx+1, vector<int>(3, -1)));

    helper(0, A, 0, max_profit, 2, dp);

    return max_profit;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define mod 1000000007
// #define pb push_back
// #define mp make_pair
// #define fi first
// #define sec second
// typedef long long ll;
// typedef long double  ld;
// #define pii pair<ll,ll>
// #define vi vector< ll >
// #define vvi vector< vi >
// #define vpi vector< pii >
// #define vvpi vector< vpi >
// #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define test(t) ll t;cin>>t;while(t--)
// #define mem(a,b) memset(a,b,sizeof(a))
// #define inn freopen("input.txt", "r", stdin)
// #define outt freopen("output.txt", "w", stdout)
// #define all(arr) arr.begin(),arr.end()
// #define fr(i,n) for(ll i=0;i<(n);++i)
// #define rep(i,a,b) for(ll i=a;i<=b;++i)
// #define per(i,a,b) for(ll i=a;i>=b;i--)
// #define remin(a,b) (a=min((a),(b)))
// #define remax(a,b) (a=max((a),(b)))
// //#define ln ListNode*
// //#define tn TreeNode*
// long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};



// void helper(int si, const vector<int> &A, int cur_profit, int &max_profit, int tr){
    
//     int n = A.size();

//     if(tr == 0 || si >= n){
//         if(cur_profit > max_profit)
//         max_profit = cur_profit;
//         return;
//     }

//     rep(i, si+1, n-1){
//         if(A[i] > A[si]){
//             helper(i+1, A, cur_profit + A[i] - A[si], max_profit, tr-1);
//         }
//     }

//     helper(si+1, A, cur_profit, max_profit, tr);
//     return;
// }

// int Solution::maxProfit(const vector<int> &A) {
//     int max_profit = INT_MIN;
//     helper(0, A, 0, max_profit, 2);

//     return max_profit;
// }