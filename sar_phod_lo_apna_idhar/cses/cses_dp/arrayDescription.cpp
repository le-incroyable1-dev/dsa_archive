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
#define vi vector<int>
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
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    int x0;
    cin >> x0;
    if (x0 == 0)
    {
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else
    {
        dp[0][x0] = 1;
    }
    for (int i = 1; i < n; i++)
    {

        int x;
        cin >> x;
        if (x == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1 && k <= m)
                    {
                        (dp[i][j] += dp[i - 1][k]) %= mod;
                    }
                }
            }
        }
        else
        {
            for (int k : {x - 1, x, x + 1})
            {
                if (k >= 1 && k <= m)
                {
                    (dp[i][x] += dp[i - 1][k]) %= mod;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        (ans += dp[n - 1][j]) %= mod;
    }
    cout << ans << endl;
}

/*Array Description (1746)
dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.
i.e. if I choose/fix some "v" for x[i] then the number of ways i can fill the array
from index 0 to i is given by dp[i][v]

We treat i = 0 separately. Either x[0] = 0, so we can replace it by anything
(i.e dp[0][v] = 1 for all v). Otherwise x[0] = v ≠ 0, so that dp[0][v] = 1 is the only allowed value.

if x[0] = 0 that means for each value that I choose for x[0] i.e. 1 <= x[0]/v <= m i get dp[0][v] = 1

Now to the other indices i > 0. If x[i] = 0, we can replace it by any value.
However, if we replace it by v, the previous value must be either v-1, v or v+1.
Thus the number of ways to fill the array up to i, is the sum of the previous value
being v-1, v and v+1. If x[i] = v from the input, only dp[i][v] is allowed (i.e dp[i][j] = 0 if j ≠ v).
Still dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1].

The complexity is O(n⋅m) with worst-case when x is all zeros.
*/