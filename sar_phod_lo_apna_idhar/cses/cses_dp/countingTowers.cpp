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

/*
Basically dp[i] means the number of ways to build a tower of height i. 
The next index means if the tile at the ith place is split or not. 
That is, if 0 the tile is split (2 tiles of 1 x 1) and if 1 we have a single tile of 2 x 1.

Finally, dp[i][0] means the number of ways to build a tower of height i
such that the top tile is split ( 2 tiles of 1x1) and dp[i][1] means number 
of ways to build a tower of height i such that the top tile is continuous (1 tile of 2 x 1)

Now for the recursive function:

If the last tile is split (dp[i][0]), it can have the following options:

It can extend both the split tiles at (i — 1): dp[i - 1][0]
It can extend on the left split tile at (i — 1): dp[i - 1][0]
It can extend on the right split tile at (i — 1): dp[i - 1][0]
It can extend none of the split tiles at (i — 1) but add it's own: dp[i - 1][0]
This means 4*dp[i -1][0]

And the last case, it can add split tiles over the continuous tile of i - 1th height: dp[i - 1][1]

dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1]

Similarly if the last tile is continuous (dp[i][1]):

It can extend the continuous tile at (i — 1): dp[i - 1][1]
It can not extend the continuous tile at (i — 1): dp[i - 1][1]
It can add a continuous tile over split tiles of (i — 1): dp[i - 1][0]
dp[i][1] = 2 * dp[i - 1][1] + dp[i - 1][0]

Hope this helps!

PS: Use an int array instead of vector in the code otherwise you'd get a TLE
*/

long long dp[10000005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 1;
    cin >> test_case;
    while (test_case--)
    {
        long long n;
        cin >> n;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1])%mod;
        }
        cout << (dp[n][0] + dp[n][1] )%mod<< endl;
    }
}