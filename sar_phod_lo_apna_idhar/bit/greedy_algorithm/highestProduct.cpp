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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int maxp3(vector<int> &A) {

    ll n = A.size();
    sort(all(A));
    reverse(all(A));

    if(n < 3)
    return 0;
    else if(n == 3)
    return A.at(0)*A.at(1)*A.at(2);

    int ans = INT_MIN;
    

    fr(i, n-2){
        ll curans;

        ll ca1 = A.at(i)*A.at(i+1)*A.at(i+2);
        if(ca1 <= INT_MAX)
        curans = ca1;

        if(n-2-i > i){
            if(A.at(n-1-i) <= 0 && A.at(n-2-i) <= 0){
                ll ca2 = A.at(i)*A.at(n-2-i)*A.at(n-1-i);

                if(ca2 > ca1 && ca2 <= INT_MAX)
                curans = ca2;
            }
        }

        if(curans > ans)
        ans = curans;

    }


    return ans;

}
