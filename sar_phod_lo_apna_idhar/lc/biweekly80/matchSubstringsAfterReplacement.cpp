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



//TLE
//O(m*n)
//105/109 passed
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

        ll n = s.size();
        ll m = sub.size();
        ll ms = mappings.size();

        if(m > n)
        return false;

        unordered_map<char, unordered_set<char>> cmap;

        fr(i, ms){

            if(cmap.find(mappings[i].at(0)) == cmap.end()){
                unordered_set<char> s;
                s.insert(mappings[i].at(1));

                cmap.insert(mp(mappings[i].at(0), s));
            }
            else{
                cmap.find(mappings[i].at(0))->second.insert(mappings[i].at(1));
            }
        }

        vector<unordered_set<char>> cvec;
        unordered_map<char, unordered_set<char>>::iterator itr;

        fr(i, m){
            itr = cmap.find(sub.at(i));

            if(itr == cmap.end()){
                unordered_set<char> s;
                s.insert(sub.at(i));
                cvec.pb(s);
            }
            else{
                unordered_set<char> s = itr->second;
                s.insert(sub.at(i));
                cvec.pb(s);
            }
        }

        unordered_set<char>::iterator citr;
        ll ci = 0;
        fr(i, n-m+1){
            citr = cvec.at(ci).find(s.at(i));

            if(citr != cvec.at(ci).end()){
                ll j = i+1;
                ll ni = -1;
                ci++;

                while(j < n && ci < m){
                    citr = cvec.at(ci).find(s.at(j));

                    if(cvec.at(0).find(s.at(j)) != cvec.at(0).end() && ni == -1)
                    ni = j;

                    if(citr != cvec.at(ci).end()){
                        ci++;
                        j++;
                    }
                    else{
                        ci = 0;
                        break;
                    }
                }

                if(ci == m)
                return true;

                if(ni != -1)
                i = ni-1;
            }
        }
        
        return false;  
        
    }

    
};

