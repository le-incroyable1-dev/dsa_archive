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
#define z '0'
#define o '1'
//#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


void sol(string s){

    ll n = s.length();
    ll ans = 0;

    ll oc = 0;
    ll zc = 0;

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    fr(i, n){
        if(s[i] == z)
        zc++;

        if(s[i] == o)
        oc++;
    }

    if(oc == 0 && zc == 0)
    ans = n;
    else if(oc == 0 && zc > 0){

        ll ind = 0;

        while(s[ind] != z)
        ind++;

        ans = ind+1;
    }
    else if(oc > 0 && zc == 0){
        ll i1 = 0;

        while(oc > 0){
            if(s[i1] == o)
            oc--;

            i1++;
        }

        i1 -= 1;

        ans = n-i1;
    }
    else{
        ll i1 = 0;
        ll i2 = 0;

        while(s[i2] != z)
        i2++;

        while(oc > 0){
            if(s[i1] == o)
            oc--;

            i1++;
        }

        i1 -= 1;

        ans = i2 - i1 + 1;
    }


    cout << ans << endl;

    
}



int main(void){
    
    fast;

    test(t){
        string s;
        cin >> s;
        sol(s);
    }
    
}