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



int solve_dp(vector<int> &arr) {

    int n = arr.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];
 
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
 
    // Initialize difference of two sums.
    int diff = INT_MAX;
 
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}



void helper(vector<int> &A, int curr, int &mn, int i, int &sum){

    int n = A.size();

    if(i >= n){
        int res = abs(sum - curr);

        if(res < mn && res > 0)
        mn = res;

        return;
    }

    helper(A, curr+A[i], mn, i+1, sum);
    helper(A, curr, mn, i+1, sum);

    return;
}

int solve(vector<int> &A) {

    int sum = 0;
    int mn = INT_MAX;

    int n = A.size();
    fr(i, n)
    sum += A[i];

    vector<vector<int>> memo(sum+1, vector<int>(n, 0));
    helper(A, 0, mn, 0, sum);

    return mn;

}


void sol(){
    
}



int main(void){
    
    fast;

    vector<int> v = {1,6,11,5};
    cout << solve_dp(v);
    return 0;
    
}