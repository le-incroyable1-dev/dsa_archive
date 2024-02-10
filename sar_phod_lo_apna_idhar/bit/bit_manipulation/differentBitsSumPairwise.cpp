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


int cntBits(vector<int> &A) {
    //long long int mod = 1e9+7;
    long long int ans=0;
    
    //look at this
    // 001  1
    // 011  3
    // 101  5
    
    // num of zeros at 0th index = 0, num of ones at 0th index = 3   ans = 0
    // num of zeros at 1st index = 2, num of ones at 1st index = 1   ans = 2C1 * 1C1
    // num of zeros at 2nd index = 2, num of ones at 2nd index = 1   ans = 2C1 * 1C1

    // considering 0th to 31st position for integers
    
    for(int i=0;i<32;i++)
    {
        long long int zeros=0;
        long long int ones=0;
        
        for(int j=0;j<A.size();j++)
        {
            if((A[j]>>i)&1==1)   ones++; 
            else    zeros++;
        }
        if(zeros==0||ones==0)   ans+=0;
        else    ans+=(zeros*ones)%mod;
    }

    return (ans*2)%mod;
}

/*
int difBits(int a, int b)
{

    int cnt = 0;

    while (a > 0 && b > 0)
    {

        int t1 = a;
        int t2 = b;

        int r1 = t1 & 1;
        int r2 = t2 & 1;

        if (r1 != r2)
            cnt++;

        a = a >> 1;
        b = b >> 1;
    }

    if (a > 0)
    {
        while (a > 0)
        {
            int t1 = a;
            int r1 = t1 & 1;

            if (r1 == 1)
                cnt++;

            a = a >> 1;
        }
    }

    if (b > 0)
    {
        while (b > 0)
        {
            int t1 = b;
            int r1 = t1 & 1;

            if (r1 == 1)
                cnt++;

            b = b >> 1;
        }
    }

    return cnt;
}

int cntBits(vector<int> &A)
{
    ll n = A.size();

    ll tcnt = 0;

    unordered_map<ll, ll> m;
    unordered_map<ll, ll>::iterator itr;

    fr(i, n){
        fr(j, n){
            itr = m.find(i+j*n);
            if(itr != m.end()){
                tcnt += itr->second%mod;
                continue;
            }

            itr = m.find(j+i*n);
            if(itr != m.end()){
                tcnt += itr->second%mod;
                continue;
            }

            int dif = difBits(A.at(i), A.at(j));

            m.insert(mp(i+j*n, dif));
            m.insert(mp(j+i*n, dif));

            tcnt += (ll)dif%mod;
        }
    }

    int ans = (int)(tcnt%mod);

    return ans;
}
*/

/*
void sol(){
}



int main(void){

    fast;

    test(t){
        sol();
    }

}
*/