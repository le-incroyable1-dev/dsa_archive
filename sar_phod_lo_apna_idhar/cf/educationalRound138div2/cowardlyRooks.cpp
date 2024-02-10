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


int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(int i, int j, int n, int m){

    if(i > 0 && i <= n && j > 0 && j <= m)
    return true;
    else
    return false;
}



int main(void){
    
    fast;

    test(t){
        int n, m;
        cin >> n >> m;
        unordered_map<int, int> rm;
        unordered_map<int, int> cm;
        vector<pair<int, int>> v;
        
        fr(i, m){
            int r,c;
            cin >> r >> c;
            v.pb(mp(r, c));
            rm[r]++;
            cm[c]++;
        }

        bool possible = false;

        fr(i, m){
            pair<int, int> cur = v[i];
            int r = cur.first;
            int c = cur.second;

            rm[r]--;
            cm[c]--;

            for(int k = 0; k < 4; ++k){
                for(int factor = 1; factor <= n; factor++){
                    int nr = r + factor*dxdy[k][0];
                    int nc = c + factor*dxdy[k][1];

                    if(isValid(nr, nc, n, n)){
                        if((!rm[nr] || rm[nr] == 0) && (!cm[nc] || cm[nc] == 0))
                        possible = true;
                    }

                    if(possible)
                    break;
                }
            }

            if(possible)
            break;

            rm[r]++;
            cm[c]++;
        }

        if(possible)
        cout << "YES";
        else
        cout << "NO";

        cout << "\n";
    }
    
}
