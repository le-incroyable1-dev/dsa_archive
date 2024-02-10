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
#define vi vector< int >
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

// ** i1 < i2,i3 < i4 

vector<int> equal(vector<int> &A) {

    ll n = A.size();
    vvi res;

    if(n < 4){
        vi v;
        return v;
    }

    unordered_map<int, vi> summap;
    unordered_map<int, vi>::iterator itr;

    fr(i, n){

        rep(j, i+1, n-1){

            int sum = A.at(j)+A.at(i);
            //cout << sum << endl;
            itr = summap.find(sum);

            if(itr != summap.end()){

                vi ans;
                //cout << "match" << sum << endl;
                vi v = itr->second;
                //cout << v.at(0) << v.at(1) << i << j << endl;

                //check if any duplicate indices are showing up
                if(v.at(0) == i || v.at(0) == j || v.at(1) == i || v.at(1) == j)
                continue;
                
                ans.pb(v.at(0));
                ans.pb(v.at(1));
                ans.pb(i);
                ans.pb(j);

                res.pb(ans);
            }
            else{

                // this else block was required because i2 and i3 may be in any order. if i2 < i3 then discard this block
                // it will also cover the case where i2 > i3
                vi v;
                v.pb(i);
                v.pb(j);
                
                summap.insert(mp(sum, v));
            }
        }

        fr(j, i){
            int sum = A.at(j)+A.at(i);
            itr = summap.find(sum);

            if(itr == summap.end()){
                vi v;
                v.pb(j);
                v.pb(i);
                //cout << "insert" << sum << endl;
                summap.insert(mp(sum, v));
            }
        }
    }

    sort(all(res));
    return res.at(0);
}

