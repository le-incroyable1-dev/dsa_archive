#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define test(t) \
    ll t;       \
    cin >> t;   \
    while (t--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(), arr.end()
#define fr(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
//#define ln ListNode*
//#define tn TreeNode*
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

// 13 5 8 18 20 3 4 6 7 12 16 18 11 1
// 8

int maxProfit(vector<int> &prices, int k)
{
    if (k == 0 || prices.size() == 0)
        return 0;
    int max_profit = 0;
    if (k >= prices.size() / 2)
    {
        for (int i = 1; i < prices.size(); i++)
        {
            max_profit += max(prices[i] - prices[i - 1], 0);
        }
        return max_profit;
    }

    vector<vector<int>> dp(k + 1, vector<int>(prices.size() + 1, 0));

    for (int i = 1; i <= k; i++)
    {
        int maxDiff = -prices[0];
        for (int j = 2; j <= prices.size(); j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j - 1]);
        }
    }
    return dp[k][prices.size()];
}

int solve(vector<int> &A, int B)
{
    assert(A.size() >= 1 && A.size() <= 500);
    for (int a : A)
        assert(a >= 0 && a <= 1e6);
    assert(B >= 0 && B <= 1e9);
    return maxProfit(A, B);
}

// int solve_dp(vector<int> &A, int B) {
//     int n = A.size();
//     int max_profit = 0;
//     int max_val = 0;

//     vector<vector<int>> dp(B, vector<int>(n, 0));

//     rep(i, 0, B-1){
//         max_val = 0;
//         rep(j, 0, n-1){
//             dp[i][j] = 0;

//             if(j > 0)
//             dp[i][j] = max(dp[i][j-1], max(dp[i][j], A[j] + max_val));

//             if(i > 0 && j > 0)
//             max_val = max(max_val, dp[i-1][j-1] - A[j]);
//         }
//     }

//     max_profit = max(max_profit, dp[B-1][n-1]);
//     return max_profit;
// }

// void helper(int s, vector<int> &A, int B, int cur_profit, int &max_profit){

//     if(cur_profit > max_profit)
//     max_profit = cur_profit;

//     if(B == 0 || s >= A.size()-1) return;

//     rep(i, s, A.size()-2){
//         rep(j, i+1, A.size()-1)
//         if(A[j] - A[i] > 0)
//         helper(j+1, A, B-1, cur_profit + (A[j] - A[i]), max_profit);
//         else
//         continue;
//     }

// }

// int solve(vector<int> &A, int B) {
//     int n = A.size();
//     int max_profit = 0;
//     helper(0, A, B, 0, max_profit);
//     return max_profit;
// }

// void sol(){

// }

// int main(void){

//     fast;

//     vector<int> A = {2, 4, 1};
//     int B = 2;

//     solve_dp(A, B);

//     return 0;

// }