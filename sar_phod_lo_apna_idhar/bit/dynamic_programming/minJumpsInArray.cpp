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


//O(n) greedy
int jump(vector<int> &A) {
    int jumps = 0, current_range = 0, next_range = 0;
    
    for(int i = 0; i <= current_range; i++) {
        if(i == A.size() - 1) {
            return jumps;
        }
        
        next_range = max(next_range, A[i] + i);
        
        if(i == current_range) {
            jumps++;
            current_range = next_range;
        }
    }
    return -1;
}

//DP O(n^2)
int jump(vector<int> &A) {

    int n = A.size();
    int dp[n];
    fr(i, n)
    dp[i] = INT_MAX;

    per(i, n-1, 0){
        if(i == n-1)
        dp[i] = 0;
        else{
            per(j, min((ll)n-1, i+(ll)A[i]), i+1){

                if(dp[j] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[j]);

            }
        }
    }

    if(dp[0] == INT_MAX)
    return -1;
    else
    return dp[0];
    
}

void sol(){
    
}



int main(void){
    
    fast;
    vector<int> A = {2 ,1 ,1, 3,4};
    cout << jump(A);

    return 0;
    
}