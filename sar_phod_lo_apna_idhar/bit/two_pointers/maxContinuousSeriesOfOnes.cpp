#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
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
#define itr(type) type::iterator itr
long long powerof2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296};

/*
10 1 0 0 0 0 0 1 0 1 1
2
*/

vector<int> maxone(vector<int> &A, int B)
{
    vector<int> v;
    int maxx = 0, p1, p2;
    queue<int> q;
    int n = A.size();
    int start = 0, end = 0;
    int zero_ct = 0;
    
    while (end < n)
    {
        if (A[end] == 0)
        {
            q.push(end);

            if (zero_ct < B)
            {
                zero_ct++;
            }
            else
            {
                start = q.front() + 1;
                q.pop();
            }
        }

        if (maxx < end - start)
        {
            maxx = end - start;
            p1 = start;
            p2 = end;
        }

        end++;
    }

    for (int i = p1; i <= p2; i++)
        v.push_back(i);

    return v;
}

/*
vector<int> maxone(vector<int> &A, int m) {

    int n = A.size();
    int l = 0, r= 0;

    int ct = 0;
    //int len = 0;
    vpi v;
    bool add = true;

    while(r < n && l < n){

        if(A.at(r) == 0 && add)
        ct++;

        if(ct < m){
            r++;

            if(r == n){
                v.pb(mp(l, r-1));
            }
            //len++;
            add = true;
        }
        else if(ct == m){
            r++;

            while(r < n && A.at(r) == 1)
            r++;

            if(r < n && A.at(r) == 0){
                v.pb(mp(l, r-1));
                //cout << l << r-1 << 0 << endl;
                ct = 0;
            }
            else if(r == n){
                v.pb(mp(l,r-1));
                //cout << l << r-1 << endl;
            }

            //len++;
            add = true;
            l = r;

        }
        else{
            if(l < n && A.at(l) == 0)
            ct--;

            l++;
            //len = 0;
            add = false;
        }

    }

    l = 0, r= 0;

    //int ct = 0;
    //int len = 0;
    vpi v2;
    //bool add = true;

    while(r < n && l < n){

        if(A.at(l) == 0){
            while(l < n && A.at(l) != 1)
            l++;

            r = l;
            continue;
        }
        else{
            if(A.at(r) == 1){
                while(r < n && A.at(r) == 1)
                r++;

                v2.pb(mp(l, r-1));

                l = r;
            }
        }
    }




//--------------------------------------------------------------
    pii maxp;
    int max = INT_MIN;

    fr(i, v.size()){

        int size = v.at(i).second - v.at(i).first;

        if(size > max){
            max = size;
            maxp = v.at(i);
        }

    }

    pii maxp2;
    int max2 = INT_MIN;

    fr(i, v2.size()){

        int size = v2.at(i).second - v2.at(i).first;

        if(size > max){
            max2 = size;
            maxp2 = v2.at(i);
        }

    }

    if(max2 > max)
    maxp = maxp2;

    vector<int> ans;

    int i = maxp.first;

    while(i <= maxp.second){
        ans.pb(i);
        i++;
    }

    return ans;
//-------------------------------------------------------------

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