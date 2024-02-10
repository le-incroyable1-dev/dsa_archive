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
#define rep(i, a, b) for (ll i = a; i <= ab; ++i)
#define per(i, a, b) for (ll i = a; i >= b; i--)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define ln ListNode *
//#define itr(type) type::iterator itr
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//reverse list from middle and merge alternatively

ListNode *reverse(ListNode *A)
{
    ListNode *p = NULL;
    ListNode *c = A;
    ListNode *n = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

ListNode *reorderList(ListNode *A)
{
    if (A == NULL)
    {
        return NULL;
    }
    ListNode *slow = A;
    ListNode *f = A->next;
    while (f != NULL && f->next != NULL)
    {
        slow = slow->next;
        f = f->next->next;
    }
    ListNode *mid = slow;
    ListNode *h2 = reverse(mid->next);
    mid->next = NULL;
    ListNode *h1 = A;
    while (h1 != NULL && h2 != NULL)
    {
        ListNode *th2 = h2->next;
        ListNode *th1 = h1->next;
        h1->next = h2;
        h2->next = th1;
        h1 = th1;
        h2 = th2;
    }
    return A;
}

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