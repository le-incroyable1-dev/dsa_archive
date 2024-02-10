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

//RECURSIVE SOLUTION

void helper(string A, vector<string> &res, vector<string> resc, ll d){

    ll n = A.length();
    ll s = n - 1;

    if(s == 0 || d == 0){
        if(stold(A) > 255)
        return;

        if(A.at(0) == '0' && n > 1)
        return;

        res.push_back(A);
        return;
    }

    ll maxs = min((ll)3, n-d);
    //cout << maxs << endl;

    ll k = 1;

    //vector<string> resc = res; //copy


    while(k <= maxs){

        if(n-k < d)
        continue;

        string newA = A.substr(k, n-k);
        string pre = A.substr(0, k);
        //cout << A << " " << newA << " " << pre << endl;
        vector<string> curset = resc;
        helper(newA, curset, curset, d-1);

        for(auto s : curset){

            if(stold(pre) > 255 || (pre.at(0) == '0' && pre.length() > 1)){
                res.erase(std::remove(res.begin(), res.end(), s), res.end());
                continue;
            }

            if(s.empty())
            continue;
            
            s = pre + "." + s;
            res.push_back(s);
        }

        k++;
    }

    return;
}

vector<string> restoreIpAddresses(string A) {

    ll n = A.length();

    vector<string> res;

    if(n < 4)
    return res;

    if(n > 12)
    return res;

    ll d = 3;

    helper(A, res,res, d);

    return res;
}
