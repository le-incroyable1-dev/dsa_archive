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


void sol(){
    
}

/*
    we dont use visited here because we will need to check for each node again
    which may have another three cycle, and marking visited will make it complicated
    instead we initially count the repeated cycles. for each cycle, its repetition will be
    counted 3*2 = 6 times (2 times for each node in the 3cycle). so, we divide the final 
    count by 6 and return it.
*/

int main() {
    // Write your code here

    fast;

    int v, e;
    cin >>  v >> e;
    
    vector<vector<int>> g(v, vector<int>(v, 0));
    
    for(int i = 0; i < e; ++i){
        int a, b;

        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    int count = 0;

    fr(sn, v){
        int node1 = sn;
        int node2 = -1;
        int node3 = -1;

        fr(i, v){
            if(g[node1][i] == 1){
                node2 = i;

                fr(j, v){
                    if(g[node2][j] == 1){
                        node3 = j;

                        if(g[node3][node1] == 1)
                        count++;
                    }
                }
            }
        }
    }

    int res = count/6;
    cout << res;

    return 0;
    
}