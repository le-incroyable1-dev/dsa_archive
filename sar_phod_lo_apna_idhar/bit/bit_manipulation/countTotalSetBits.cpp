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
#define itr(type) type::iterator itr
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

/*
If we observe bits from rightmost side at distance i
then bits get inverted after 2^i position in vertical sequence.

For example A = 5;
0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101

Observe the right most bit (i = 0) the bits get flipped after (2^0 = 1)
Observe the 3rd rightmost bit (i = 2) the bits get flipped after (2^2 = 4)

So, We can count bits in vertical fashion such that at i’th right most
position bits will be get flipped after 2^i iteration;
*/

int solve(int n){

    ll num = (ll)n+1;
    ll ans = 0;

    for(int i = 0; i <= 31; i++){

        //gandit lgao
        ll v1 = ((num-(ll)pow(2, i))/((ll)pow(2, i+1)))*((ll)pow(2, i));
        ll v2 = min((num-(ll)pow(2, i))%((ll)pow(2, i+1)), (ll)pow(2, i));

        (ans += v1)%=mod;
        (ans += v2)%=mod;

        ans %= mod;
    }

    if(ans >= INT_MAX)
    return INT_MAX;
    else
    return (int)ans;
}

int solve2(int n)
{

    if (n == 0)
        return 0;

    int t = n + 1;
    long long count = 0;
    
    for (int x = 2; x <= 2 * (t - 1); x = x * 2)
    {
        count += (t / x) * x / 2;

        if ((t % x) > x / 2)
        {
            count += (t % x) - (x / 2);
        }
    }
    return count % 1000000007;
}

/*

//TLE :(

int solve(int A) {

    ll ans = 0;

    if(A == 0)
    return 0;

    //ll limit = ceil(A/2);

    fr(i, 32){
        //int a  =A;
        int s = 1;

        fr(j, A){
            int temp = s;
            temp = temp >> i;

            temp = temp&1;
            if(temp == 1)
            ans++;

            s++;
        }

        ans = ans%mod;
    }

    return (int)ans%mod;
}

*/

int main(void)
{

    fast;

    test(t)
    {
        // solve();
    }
}