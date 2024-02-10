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


void sol(ll n, vi v){

    sort(all(v));
    reverse(all(v));

    ll ei = -1;
    ll oi = -1;

    fr(i, n){
        if(v[i]%2 == 0){
            ei = i;
            break;
        }
    }

    fr(i, n){
        if(v[i]%2 != 0){
            oi = i;
            break;
        }
    }

    ll ans = 0;
    bool e1 = false;
    bool e2 = false;

    fr(i, n){
        if(i%2 == 0){
            if(i == 0){
                if(i == ei){
                    e1 = false;
                    ans += v[i];

                    ei++;
                    while(v[ei]%2 != 0  && ei <  n)
                    ei++;

                    if(ei == n)
                    ei == -1;
                }
                else if(i == oi){
                    e1 = true;
                    ans += v[i];

                    oi++;
                    while(v[oi]%2 == 0 && oi < n)
                    oi++;

                    if(oi == n)
                    oi = -1;
                }
            }
            else{
                if(e1 == false){
                    if(oi == -1){
                        e1 = true;
                    }
                    else{
                        ans += v[oi];

                        oi++;
                        while(v[oi]%2 == 0 && oi < n)
                        oi++;

                        if(oi == n)
                        oi = -1;
                    }
                }
                else{
                    if(ei == -1){
                        e1 = false;
                    }
                    else{
                        ans += v[ei];

                        ei++;
                        while(v[ei]%2 != 0 && ei < n)
                        ei++;

                        if(ei == n)
                        ei = -1;
                    }
                }
            }
        }
        else{

            if(i == 1){
                if(i == ei){
                    e2 = false;
                    //ans += v[i];

                    ei++;
                    while(v[ei]%2 != 0  && ei <  n)
                    ei++;

                    if(ei == n)
                    ei == -1;
                }
                else if(i == oi){
                    e2 = true;
                    //ans += v[i];

                    oi++;
                    while(v[oi]%2 == 0 && oi < n)
                    oi++;

                    if(oi == n)
                    oi = -1;
                }
            }
            else{
                if(e2 == false){
                    if(oi == -1){
                        e1 = true;
                    }
                    else{
                        //ans += v[oi];

                        oi++;
                        while(v[oi]%2 == 0 && oi < n)
                        oi++;

                        if(oi == n)
                        oi = -1;
                    }
                }
                else{
                    if(ei == -1){
                        e2 = false;
                    }
                    else{
                        //ans += v[ei];

                        ei++;
                        while(v[ei]%2 != 0 && ei < n)
                        ei++;

                        if(ei == n)
                        ei = -1;
                    }
                }
            }

        }
    }

    cout << ans << endl;
}



int main(void){
    
    fast;

    test(t){

        ll n;
        cin >> n;

        ll ele;
        vi v;

        fr(i, n){
            cin >> ele;
            v.pb(ele);
        }


        sol(n, v);
    }
    
}