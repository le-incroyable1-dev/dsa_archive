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


/*

You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in 
L exactly once and without any intervening characters.

*/

//O(m*n) solution

vector<int> findSubstring(string A, const vector<string> &B) {

    ll n = A.size();
    ll m = B.size();
    ll ws = B[0].length();

    vi res;

    if(m*ws > n)
    return res;

    ll val = 0;

    unordered_map<string, int> mapp;
    unordered_map<string, int>::iterator itr;

    fr(i, m){

        itr = mapp.find(B.at(i));

        if(itr == mapp.end()){
            mapp.insert(mp(B.at(i), 1));
        }
        else
        itr->second++;
    }

    

    fr(i, n-ws+1){

        string cur = A.substr(i, ws);
        itr = mapp.find(cur);
        
        //cout << i << endl;

        if(itr != mapp.end()){

            int init = i;
            int count = 0;

            unordered_map<string, int> mapcpy = mapp;
            itr = mapcpy.find(cur);
            
            ll j = i;

            while(itr != mapcpy.end() && count < m && j < n-ws+1){
                
                itr->second--;
                if(itr->second == 0)
                mapcpy.erase(itr);
                
                count++;

                if(count == m){
                    res.pb(init);
                    //cout << endl << init << endl << endl;
                    break;
                }

                j += ws;
                
                if(j > n-ws)
                break;
                
                
                string cur = A.substr(j, ws);
                itr = mapcpy.find(cur);
            }
            
            
        }
        else
        continue;
        
    }
    
    return res;

}










/*

//O(n^2 * m) solution
//Brute force approach

vector<int> Solution::findSubstring(string A, const vector<string> &B) {

    int n = A.size();
    vector<int> ans;
    int len = 0;
    for(int i=0;i<B.size();i++){
        len+=B[i].size();
    }
    string ss = "**";
    for(int i=0;i<n+1-len;i++){
        string str = A.substr(i,len);
            int cnt = 0;
            for(int j=0;j<B.size();j++){
                if(str.find(B[j])!=string::npos)
                {cnt++;str.replace(str.find(B[j]),B[0].size(),ss);}//for repetating elements
            }
            if(cnt==B.size())ans.push_back(i);
        
    }
    return ans;
}

*/