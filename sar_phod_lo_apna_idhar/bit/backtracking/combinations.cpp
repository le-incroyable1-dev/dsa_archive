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



void helper(vi cur, vvi &ans,int A, int count, int B, int ci){

    if(count > B) return;
    else if(count == B){

        /*
        sort(cur.begin(), cur.end());

        for(auto x:ans){
            if(x == cur) return;
        }
        */

        ans.pb(cur);
        return;
    }

    if(count + 1 <= B){
        rep(i, ci, A-1){
            bool flag = true;

            /*
            for(auto x:cur){
                if(i+1 == x){
                    flag = false;
                    break;
                }
            }
            */

            if(flag){
                cur.pb(i+1);
                helper(cur, ans, A, count+1, B, i+1);
                cur.pop_back();
            }
        }
    }
}

vector<vector<int> > combine(int A, int B) {

    vvi ans;

    vi cur;

    if(B > A)
    return ans;
    else if(B == A){
        fr(i, A)
        cur.pb(i+1);

        ans.pb(cur);
        return ans;
    }

    helper(cur, ans, A, 0, B, 0);
    return ans;
}



void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}