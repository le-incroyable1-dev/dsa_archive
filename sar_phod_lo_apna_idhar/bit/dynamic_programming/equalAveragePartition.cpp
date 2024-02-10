#include <bits/stdc++.h>
using namespace std;
int tot_sum = 0;


bool canTake(vector<int> &v, int sz, int sum, int i, int n){
    
    if(i == n) return (sum == 0 && sz == 0);
    if(sum == 0) return (sz == 0);
    if(sz == 0) return (sum == 0);
    
    
    bool res = false;
    
    res |= canTake(v, sz, sum, i+1, n);
    
    if(sum >= v[i])
    res |= canTake(v, sz-1, sum-v[i], i+1, n);
    
    
    return res;
}


void build(vector<int> &v, vector<int> &p1, int i, int n, int sz, int sum, bool &done){
    if(done) return;
    if(sz == 0 && sum == 0){
        done = true;
        return;
    }

    if(i == n) return;
    if(sum == 0 || sz == 0) return;

    build(v,p1,i+1,n,sz,sum,done);

    if(done) return;

    p1.push_back(v[i]);
    build(v,p1,i+1,n,sz-1,sum-v[i],done);

    if(done) return;
    else p1.pop_back();

    return;
}

vector<vector<int>> avgset(vector<int> &v) {
    
    int n = v.size();
    for(auto val : v) tot_sum += val;
    
    float req = (float)tot_sum/(float)n;
    
    if(ceil(req) != floor(req)) return {{}};
    
    
    int req_sz = -1;
    
    for(int sz = 1; sz <= n; ++sz){
        int req_sum = req * sz;
        
        if(canTake(v, sz, req_sum, 0, n)){
            req_sz = sz;
            break;
        }
        
    }
    
    if(req_sz == -1) return {{}}; 

    vector<vector<int>> ans;
    bool done = false;

    vector<int> p1;
    build(v,p1,0,n,req_sz,req*req_sz,done);
    //reverse(p1.begin(), p1.end());

    vector<int> p2;
    int i = 0;
    int j = 0;

    while(i < n && j < req_sz){
        if(v[i] == p1[j]) ++j;
        else p2.push_back(v[i]);

        ++i;
    }

    while(i < n) p2.push_back(v[i]), ++i;

    ans.push_back(p1);
    ans.push_back(p2);

    return ans;

}

int main(){
    vector<int> v = {1,7,15,29,11,9};
    vector<vector<int>> res = avgset(v);
}

// #include<bits/stdc++.h>
// using namespace std;
// #define mod 1000000007
// #define pb push_back
// #define mp make_pair
// #define fi first
// #define sec second
// typedef long long ll;
// typedef long double  ld;
// #define pii pair<ll,ll>
// #define vi vector< ll >
// #define vvi vector< vi >
// #define vpi vector< pii >
// #define vvpi vector< vpi >
// #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define test(t) ll t;cin>>t;while(t--)
// #define mem(a,b) memset(a,b,sizeof(a))
// #define inn freopen("input.txt", "r", stdin)
// #define outt freopen("output.txt", "w", stdout)
// #define all(arr) arr.begin(),arr.end()
// #define fr(i,n) for(ll i=0;i<(n);++i)
// #define rep(i,a,b) for(ll i=a;i<=b;++i)
// #define per(i,a,b) for(ll i=a;i>=b;i--)
// #define remin(a,b) (a=min((a),(b)))
// #define remax(a,b) (a=max((a),(b)))
// //#define ln ListNode*
// //#define tn TreeNode*
// long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};



// vector<vector<int>> avgset(vector<int> &A) {

//     int n = A.size();
//     int sum = 0;
//     fr(i, n)
//     sum += A[i];
//     int target = sum/n;
//     vector<vector<int>> res;

//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(sum+1, vector<int>(1, -1)));

//     dp[0][0] = {};
//     rep(i, 1, n-1){
//         dp[i][0] = {};
//     }
    

//     vector<int> path;

//     bool done = false;

//     rep(i, 0, n){
//         rep(j, 0, sum){

//             if(!(dp[i][j].size() == 1 && dp[i][j][0] == -1))
//             continue;

//             if(i > 0)
//             int el = A[i-1];

//             vector<int> v1;
//             vector<int> v2;

//             if(i > 0 && !(dp[i-1][j].size() == 1 && dp[i-1][j][0] == -1)){
//                 dp[i][j] = dp[i-1][j];
//             }
//             else{
//                 if(i > 0 && j >= A[i-1] && !(dp[i-1][j-A[i-1]].size() == 1 && dp[i-1][j-A[i-1]][0] == -1)){
//                     vector<int> v = dp[i-1][j-A[i-1]];
//                     v.pb(A[i-1]);

//                     dp[i][j] = v;
//                 }
//             }

//             if(i!=0 && j/i == target && !(dp[i][j].size() == 1 && dp[i][j][0] == -1)){
//                 path = dp[i][j];
//                 done = true;
//             }

//             if(done)
//             break;

//         }

//         if(done)
//         break;
//     }

  

//     return res;
// }



// void sol(){
    
// }



// int main(void){
    
//     fast;

//     vector<int> A = {1,7,15,29,11,9};
//     avgset(A);

//     return 0;
    
// }