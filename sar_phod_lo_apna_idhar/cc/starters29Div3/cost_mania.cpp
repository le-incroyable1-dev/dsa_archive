//Max Heat Problem Code: COST_MANIA
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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


//INCOMPLETE
void sol(ll n, ll d, vi aprop, vi bprop){

    vpi bp;

    fr(i, n){
        bp.pb(mp(bprop.at(i), i+1));
    }

    sort(all(bp));

    ll maxHeat = LLONG_MIN;
    ll curHeat = LLONG_MIN;

    fr(i, n-1){
        ll j = i+1;
        
        cout << j << endl;

        if(aprop.at(bp.at(i).second-1) <= bp.at(j).second-1){
            curHeat = (bp.at(i).second*bp.at(j).second) - d*(bp.at(i).first^bp.at(j).second);
            cout << curHeat << endl;

            if(curHeat > maxHeat)
            maxHeat = maxHeat;

        }
    }

    cout << maxHeat << endl << endl;

}



int main(void){
    
    fast;

    test(t){
        ll n, d;
        cin >> n >> d;

        vi aprop;
        vi bprop;

        ll ele;

        fr(i, n){
            cin >> ele;
            aprop.pb(ele);
        }


        fr(i, n){
            cin >> ele;
            bprop.pb(ele);
        }


        sol(n, d, aprop, bprop);
    }
    
}