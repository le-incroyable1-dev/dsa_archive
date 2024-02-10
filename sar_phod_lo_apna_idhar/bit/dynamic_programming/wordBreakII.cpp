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


//correct recursive code, simply memoize
vector<string> helper(string A, vector<string> &B, int index){

    int n = A.length();
    vector<string> res;

    if(index >= n){
        res.pb("");
        return res;
    }

    int m = B.size();

    fr(i, m){
        string cur = "";
        if(A.find(B[i], index) == index){
            cur += B[i];
        }

        if(cur.length() > 0){
            int nxt_index = index + cur.length();
            vector<string> nxt = helper(A, B, nxt_index);
            if(nxt.size() > 0){
                for(auto str : nxt){
                    string snew;
                    if(str.length() == 0)
                    snew = cur;
                    else
                    snew = cur + " " + str;

                    res.pb(snew);
                }
            }
        }
    }

    return res;
}

vector<string> wordBreak(string A, vector<string> &B) {

    return helper(A, B, 0);
}



void sol(){
    
}



int main(void){
    
    fast;

    string A = "catsanddog";
    vector<string> B = {"cat", "cats", "and", "sand", "dog"};
    for(auto str : wordBreak(A,B))
    cout << str << endl;

    return 0;
}