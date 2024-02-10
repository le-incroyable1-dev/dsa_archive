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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};



vector<vector<int>> threeSum(vector<int> &A) {

    ll n = A.size();
    sort(A.begin(), A.end());
    vvi sets;

    fr(i, n-2){

        ll l = i+1;
        ll r = n-1;

        if(A.at(i) > 0)
        break;

        while(l < r && l < n-1 && r < n){

            ll sum = (ll)((ll)A.at(i) + (ll)A.at(l) + (ll)A.at(r));
            //cout << sum << endl;


            //handle overflow
            
            if(sum < (ll)INT_MIN){
                r++;
                continue;
            }

            if(sum > (ll)INT_MAX){
                l--;
                continue;
            }

            int curSum = (int)sum;

            if(curSum == 0){
                vi v;
                v.pb(A.at(i));
                v.pb(A.at(l));
                v.pb(A.at(r));

                sets.pb(v);

                l++;
                r--;
            }
            else if(curSum < 0){
                l++;
            }
            else if(curSum > 0){
                r--;
            }

            continue;
        }
    }

    /*
    vvi::iterator itr;
    itr = sets.begin();
    vector<vvi::iterator> itrv;

    while(itr != sets.end()){

        if(itr+1 == sets.end())
        break;
        
        if(itr->at(0) == (itr+1)->at(0) && itr->at(1) == (itr+1)->at(1) && itr->at(2) == (itr+1)->at(2))
        itrv.pb(itr);

        itr++;
    }

    fr(i, itrv.size())
    sets.erase(itrv.at(i));
    */

    //unordered_map<int, int> mapp;
    //unordered_map<vi, int> mapp;

    set<vi> s;
    unsigned size = sets.size();
    for( unsigned i = 0; i < size; ++i ) s.insert( sets[i] );
    sets.assign(s.begin(), s.end());

    return sets;
}

//19 1 -4 0 0 5 -5 1 0 -2 4 -4 1 -1 -4 3 4 -1 -1 -3
//5 2147483647 -2147483648 -2147483648 0 1


void sol(){


}



int main(void){
    fast;

    
    return 0;
}