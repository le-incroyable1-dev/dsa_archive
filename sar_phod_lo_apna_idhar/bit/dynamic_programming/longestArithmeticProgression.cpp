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

int solve(const vector<int> &A) {

    ll n = A.size();
    if(n == 0 || n == 1)
    return n;

    int ans = 2;

    int dp[n][n];

    unordered_map<int, int> m;


    rep(i, 0, n-1){

        m[A[i]] = i;
        
        rep(j, i+1, n-1){
            dp[i][j] = 2;
            int req = 2*A[i] - A[j];

            if(m.find(req) != m.end()){
                int k = m.find(req)->second;
                if(k < i)
                dp[i][j] = max(dp[i][j], 1 + dp[k][i]);
            }

            ans = max(ans, dp[i][j]);
        }
    }
    

    return ans;
}


int solve2(const vector<int> &A) {

    ll n = A.size();
    if(n == 0 || n == 1)
    return n;

    int ans = 2;
    
    unordered_set<int> s;
    
    rep(i, 0, n-1){
        rep(j, i+1, n-1){
            int r = A[j]-A[i];
            
            if(s.find(r) != s.end())
            continue;
            else
            s.insert(r);
            
            
            int last = A[j];
            int count = 2;

            rep(k, j+1, n-1){
                if(A[k] - last == r){
                    last = A[k];
                    count++;
                }
            }

            ans = max(ans, count);
        }
    }

    s.clear();

    return ans;
}

// int solve(const vector<int> &A) {

//     // vector<int> A = v;
//     // sort(all(A));

//     int n = A.size();
//     if(n == 0 || n == 1)
//     return n;

//     pair<int, int> dp[n];
//     fr(i, n)
//     dp[i] = mp(0, 0);

//     int ans = 2;

//     dp[0] = mp(1, -1);
//     dp[1] = mp(2, A[1]-A[0]);

//     rep(i, 2, n-1){
//         rep(j, 0, i-1){
//             if(j == 0){
//                 dp[i].first = 2;
//                 dp[i].second = A[i]-A[0];
//             }
//             else{
//                 if(dp[j].second == A[i]-A[j]){
//                     //dp[i].first = max(dp[i].first, 1 + dp[j].first);
//                     if(dp[i].first < 1 + dp[j].first){
//                         dp[i].first = 1 + dp[j].first;
//                         dp[i].second = dp[j].second;
//                     }
//                 }
//             }
//         }

//         ans = max(ans, dp[i].first);
//     }

//     //A.clear();

//     return ans;
// }



void sol(){
    
}



int main(void){
    
    fast;

    vector<int> v = {9, 4, 7, 2, 10};
    cout << solve(v) << endl;
    
}