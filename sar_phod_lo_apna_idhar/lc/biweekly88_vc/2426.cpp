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

class Solution
{

public:

    //O(n*logn*logn)
    long long int count;

    void checkCount(vector<int> &nums, int start, int mid, int end, int d)
    {

        int l = start, r = mid + 1;
        while (l <= mid && r <= end)
        {
            if (nums[l] <= (nums[r] + d)) // if (nums[l]<=nums[r]+d) then all values from nums[r] to nums[end] will be greater than or equal to nums[l]
            {
                count += (end - r + 1);
                l++;
            }
            else // otherwise we need to increment r so that we can find match for nums[l]
            {
                r++;
            }
        }
        // sort all values from start to end
        sort(nums.begin() + start, nums.begin() + end + 1); // (Sort using two-pointers for better time complexity)
        return;
    }

    void mergeSort(vector<int> &nums, int start, int end, int d)
    {
        if (start == end)
            return;

        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, d);
        mergeSort(nums, mid + 1, end, d);

        checkCount(nums, start, mid, end, d);
        return;
    }

    long long numberOfPairs(vector<int> &a, vector<int> &b, int d)
    {
        count = 0;
        int n = a.size();
        vector<int> c(n);

        for (int i = 0; i < n; i++)
            c[i] = a[i] - b[i];

        mergeSort(c, 0, n - 1, d);

        return count;
    }
};