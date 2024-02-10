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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


//Knuth-Morris-Pratt Algorithm for Pattern Matching

void kmp(string &s, string &p){

    ll n = s.length();
    ll m = p.length();
    vi matches;

    //precomputations

    ll pi[m];
    mem(pi, 0);

    ll k = 0; //length of longest prefix being matched to the suffix of pattern[0...i]
    rep(i, 1, m-1){
        while(k > 0 && p[k] != p[i])
        k = pi[k-1]; // as pi is 0 indexed length k refers to index k-1

        if(p[k] == p[i])
        k++;

        pi[i] = k;
    }

    cout << "precomputation :" << endl;

    for(auto val : pi)
    cout << val << " ";

    cout << endl << endl;

    //pattern_matching

    ll i = 0;
    ll j = 0;

    while(i <= n-m){

        j = 0;

        if(s[i] == p[j]){

            ll start = i;

            i++;
            j++;
            ll len = 1;

            while(len < m && s[i] == p[j]){
                i++;
                j++;
                len++;
            }

            if(len == m)
            matches.pb(start);

            i = start + (len-pi[len-1]);
            //do the appropriate shift
        }
        else{
            i++;
            //move to the next character if this didn't match
        }
    }

    cout << "pattern matched at indices :" << endl;

    for(auto match : matches)
    cout << match << " ";

    cout << endl;
    return;
}



int main(void){
    
    fast;

    string s, p;
    cin >> s >> p;

    kmp(s, p);

    return 0;
    
}