#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
//#define fi first
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

int threeSumClosest(vector<int> &A, int B)
{
    long long int res = INT_MAX;
    int i, ans;
    sort(A.begin(), A.end());
    for (i = 0; i < A.size() - 1; i++)
    {
        int l = i + 1;
        int r = A.size() - 1;
        while (l < r)
        { 
            long long int sum = long(A[i]) + long(A[l]) + long(A[r]);
            if (sum - B == 0)
            {
                l++;
                r--;
            }
            else if (sum < B)
            {
                l++;
            }
            else
            {
                r--;
            }


            if (abs(sum - B) < res)
            {
                res = abs(sum - B);
                ans = sum;
            }

        }
    }
    return ans;
}

/*
int threeSumClosest(vector<int> &A, int B) {

    ll n = A.size();

    if(n < 3)
    return 0;

    if(n == 3)
    return A.at(0) + A.at(1) + A.at(2);

    sort(all(A));

    ll ff;
    int sum = 0;

    int curdif = INT_MAX;
    fr(i, n){
        if(B-A.at(i) < curdif){
            curdif = B-A.at(i);
            ff = i;
        }
    }

    cout << A.at(ff) << endl;

    sum += A.at(ff);

    int nB = B - sum;

    ll s = 0;
    ll t = 1;
    ll fs = 0;
    ll ft = 1;

    int minDif = INT_MAX;

    vector<int> nA;

    fr(i, n){
        if(i != ff)
        nA.pb(A.at(i));
    }

    while (s < n-1 && t < n-1 && s < t){

        int csum = nA.at(s) + nA.at(t);

        if(nB - csum < minDif){
            minDif = nB - csum;
            fs = s;
            ft = t;

            if(s < t-1)
            s++;
            else
            t++;

            continue;
        }

        if(csum < nB){

            if(s < t-1)
            s++;
            else
            t++;

            continue;
        }
        else
        break;
    }

    cout << nA.at(fs) << endl << nA.at(ft) << endl;

    sum += nA.at(fs);
    sum += nA.at(ft);

    return sum;

}
*/

/*
5 2147483647 -2147483648 -2147483648 0 1
0
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