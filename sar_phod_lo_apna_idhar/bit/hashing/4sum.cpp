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
//#define itr(type) type::iterator itr
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

// EDITORIAL
// O(n^2)
// IMP!
vector<vector<int>> fourSum(vector<int> &num, int target)
{

    sort(num.begin(), num.end());

    //hash for :- the sum, and the set containing the pairs of integers corresponding to that sum
    unordered_map<int, set<pair<int, int>>> hash;

    set<vector<int>> ans;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = num[i] + num[j];

            //if a sum corresponding to (target - a) exists in the hash
            if (hash.count(target - a))
            {
                for (auto &p : hash[target - a])
                {
                    vector<int> b = {p.first, p.second, num[i], num[j]};
                    ans.insert(b);
                }
            }
        }

        // storing pairs only upto i neatly removes the possibility of duplicates occuring in the answer
        for (int j = 0; j < i; j++)
        {
            int a = num[j], b = num[i];

            //insert the sum into the hash!
            hash[a + b].insert(make_pair(a, b));
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}
