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


string minWindow(string A, string B) {

    vector<int> m(256, 0);
    for (auto c : B)  m[c]++;
      
    int count = B.size();
    int l = 0, r = 0, f = 0, lmin = INT_MAX;
    
    bool check=false;// to check that at least once count is reaching 0

    while (r < A.size())
    {
        if (m[A[r]] > 0)  count--;

        m[A[r]]--;
        r++;

        if(count == 0) check=true;

        while (count == 0){

            if (r - l < lmin){
                lmin = r - l;
                f = l;
            }

            if (m[A[l]] >= 0)  count++;

            m[A[l]]++;
            l++;
        }

    }

    if(check) return A.substr(f, lmin);
    else return "";

}

//TLE
/*
string minWindow(string s, string t) {

    string res = "";
    ll wlen = LLONG_MAX;

    ll n = s.size();
    ll m = t.size();

    if(n < m)
    return res;

    if(m == 0 || n == 0)
    return res;

    unordered_map<char, ll> mapp;
    unordered_map<char, ll>::iterator itr;

    fr(i, m){
        itr = mapp.find(t.at(i));

        if(itr == mapp.end()){
            mapp.insert(mp(t.at(i), 1));
        }
        else
        itr->second++;
    }

    fr(i, n){

        itr = mapp.find(s.at(i));

        if(itr == mapp.end())
        continue;
        else{

            ll count = 0;
            unordered_map<char, ll> mapcpy = mapp;

            ll l = i;
            ll r = i;
        
            
            itr = mapcpy.find(s.at(i));
            
            int ni = i;

            while(l < n && r < n){
                
                unordered_map<char, ll>::iterator citr;
                citr = mapcpy.find(s.at(r));
                itr = mapp.find(s.at(r));
                
                if(count == 1 && itr != mapp.end() && ni == i){
                    ni = r;
                }
                
                if(citr != mapcpy.end()){

                    if(count == 1 && ni == i)
                    ni = r;

                    count++;
                
                    citr->second--;

                    if(citr->second == 0)
                    mapcpy.erase(citr);
                }

                if(count == m){

                    if(r-l+1 < wlen){
                        wlen = r-l+1;
                        res = s.substr(l, r-l+1);
                        //cout << wlen << " " << res << endl;
                        break;
                    }
                }

                r++;
            
            }

            if(count < m && r == n)
            return res;

            
            if(ni != i)
            i = ni-1;
        }

        
    }

    return res;
}
*/

/*
j67yluuhZeBQ5WCYpPz0ff39V92gJaaGHb3onlwjh3SH2mllTHGLQ9W8QsDGVH1lbLqxgF1LssG2pkIpyUhE3XUrnnNvLVFthuVVjB0r1BnP4G1HgXTcWlEMf34yaqhiEtjydTweHwIcVTN2z4uOgIC0oluZf4TiF19Amliay9BVu9U1V9cE4VB453fFAEk08DgqDVERGhKXWpmY99De07dEyCjyfj8KoGpuEOOLAZFiykrwcXcB59NPc4sLTxDgrbSoUMQ2Uj5WIxFVE1wHBEy2szh8BqGSY1RqXnU2yXeFzQiHck0aEhkDiZqv5H6EEjjFPLye15hedHL89g1nvP4OAI7l28KeV7K4sV9CtNbHswHh9ZgXYxgGl9RdnFHwHznOYsaGv2A29xPJ31eGFqzufugkGIBcBynLYXJoJkST3nCDongOkPg9gBtmj5cmR5rpxu2MNL6soZu3UnoMeM19OzDZvV7Z989bpBZQTGL8qZ5Mom2yJUkDi11GS0DKQl2Gq1hAOXdje3qKnypbLVm3SUOo4kJsgnP2DuVhotnxMgOT0N8oayTrgGD0AHZiHfAV85alLTePLVItmtjQQQ5VhWRXbQODRklscZTYeL24t3JogADEN8YxPeFZgDhfnKWPebdL0g9mNpbH3gSyzIGIEV0B03nHZqnaARXWyhLRzeqIAAwpYc70Nd4vwzGSF1xjQNZT5yVp5KpBZPbGGd3xMD7QLLV6B2pDSDXdREFDpzfxjLuCnm45FziDlJtDFIj0y6oMRT0XLjtG25HG4gDqVxCRxIwfGxbCyByVeQBQGvMcbMmxWGXuJolneC8pxjvVvAnXi
mGGgXcmFoAfmoVwBvXE2Jy4uZO2RAuoCQ

EjjFPLye15hedHL89g1nvP4OAI7l28KeV7K4sV9CtNbHswHh9ZgXYxgGl9RdnFHwHznOYsaGv2A29xPJ31eGFqzufugkGIBcBynLYXJoJkST3nCDongOkPg9gBtmj5cmR5rpxu2MNL6soZu3UnoMeM19OzDZvV7Z989bpBZQTGL8qZ5Mom

*/