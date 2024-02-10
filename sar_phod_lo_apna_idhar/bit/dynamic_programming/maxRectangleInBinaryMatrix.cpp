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


//solution using largest rectangle in histogram approach
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int>st;
    int leftSmall[n]; int rightSmall[n];
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()) leftSmall[i] = 0;
        else leftSmall[i] = st.top()+1;
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) rightSmall[i] = n-1;
        else rightSmall[i] = st.top()-1;
        st.push(i);
    }
    int maxA = 0;
    for(int i=0;i<n;i++){
        maxA = max(maxA, heights[i]*(rightSmall[i] - leftSmall[i] +1));
    }
    return maxA;
}


int maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int maxi = 0;
    vector<int>vec(m); // columns
    for(int j = 0;j<m;j++){
        vec[j] = A[0][j];
    }

    maxi = largestRectangleArea(vec);
    for(int i = 1;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 0)
                vec[j] = 0;
            else{
                vec[j] += A[i][j];
            }
        }
        maxi = max(largestRectangleArea(vec) , maxi);
    }

    return maxi;
}
// int maximalRectangle(vector<vector<int> > &A) {

//     int n = A.size();
//     int m = A[0].size();

//     if(n == 0 || m == 0)
//     return 0;

//     vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, mp(0, 0)));
    
    
//     int ans = 0;

//     if(A[0][0] == 1)
//     dp[0][0] = mp(1,1);
    
//     ans = max(ans, dp[0][0].fi * dp[0][0].sec);

//     rep(i, 1, n-1){
        
//         if(A[i][0] == 1)
//         dp[i][0] = mp(1, dp[i-1][0].second + 1);
        
//         ans = max(ans, dp[i][0].fi * dp[i][0].sec);
//     }

//     rep(i, 1, m-1){
        
//         if(A[0][i] == 1)
//         dp[0][i] = mp(dp[0][i-1].first + 1, 1);
        
//         ans = max(ans, dp[0][i].fi * dp[0][i].sec);
//     }
    

//     rep(i, 1, n-1){
//         rep(j, 1, m-1){
            
//             if(A[i][j] == 0)
//             continue;
            
//             dp[i][j] = mp(1, 1);
            
//             int x = max(1, min(dp[i-1][j].first, min(1 + dp[i-1][j-1].first, 1 + dp[i][j-1].first)));
//             int y = max(1, min(1 + dp[i-1][j].sec, min(1 + dp[i-1][j-1].sec, dp[i][j-1].sec)));

//             if(1 + dp[i-1][j].sec > x*y){
//                 x = 1;
//                 y = 1 + dp[i-1][j].sec;
//             }

//             if(1 + dp[i][j-1].fi > x*y){
//                 x = 1 + dp[i][j-1].fi;
//                 y = 1;
//             }

//             dp[i][j] = mp(x, y);
//             ans = max(ans, x*y);
            
//         }
    
//     }

//     return ans;

// }

void sol(){
    
}



int main(void){
    
    fast;

    vector<vector<int>> A = {{1,1,1}, {0,1,1}, {1,0,0}};
    cout << maximalRectangle(A) << endl;
    
}