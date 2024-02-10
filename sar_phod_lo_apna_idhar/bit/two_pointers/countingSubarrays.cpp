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
#define vpi vector<pii> c
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
SLIDING WINDOW

An efficient solution is based on sliding window technique that can be used to solve the problem.
We use two pointers start and end to represent starting and ending point of sliding window.
(Not that we need to find contiguous parts).

Initially both start and end point to the beginning of the array, i.e. index 0. Now, let’s try to add a new element el.
There are two possible conditions.

1st case :
If sum is less than B, increment end by one position. So contiguous arrays this step produce are (end – start).
We also add el to previous sum. There are as many such arrays as the length of the window.

2nd case :
If sum becomes greater than or equal to B, this means we need to subtract starting element from sum so that
the sum again becomes less than B. So we adjust the window’s left border by incrementing start.

We follow the same procedure until end < array size.

Time complexity : O(N).
*/

int solve(vector<int> &A, int B)
{

    int n = A.size();
    int i = 0, j = 0;
    int ans = 0;
    int sum = 0, prej = -1;

    while (i < n && j < n)
    {
        if (j != prej)
            sum += A[j];
            
        if (sum < B)
        {
            ans += (j - i) + 1;
            prej = j;
            j++;
        }
        else
        {
            prej = j;
            sum -= A[i];
            i++;
        }
    }
    return ans;
}

/*

int solve(vector<int> &A, int B) {

    //sort(all(A));
    ll n = A.size();

    int ans = 0;
    ll curSum = 0;

    ll l = 0;
    ll r = 0;

    curSum += A.at(0);

    while(l < n && l <= r){

        if(curSum < B){
            r++;
            ans += r-l+1;

        }
    }

    return ans;
}

*/

void sol()
{
}

int main(void)
{

    fast;

    test(t)
    {
        sol();
    }
}