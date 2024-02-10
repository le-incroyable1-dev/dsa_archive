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



int helper(vector<vector<int>> &A, int i, int j){

    int n = A.size();
    int m = A[0].size();

    if(i >= n || j >= m)
    return INT_MAX;

    if(i == n-1 && j == m-1){
        if(A[i][j] >= 0)
        return 1;
        else
        return abs(A[i][j]) + 1;
    }

    int rt = helper(A, i, j+1);
    int dn = helper(A, i+1, j);
    
    int curr = min(rt, dn);
    int res;
    
    //cout << rt << " " << dn << " " << curr << endl;
    
    if(rt == INT_MAX && dn == INT_MAX)
    return INT_MAX;
    
    if(A[i][j] >= 0){
        res = max(1, curr - A[i][j]);
    }
    else{
        res = curr + abs(A[i][j]);
    }

    
    return res;
}


int calculateMinimumHP(vector<vector<int> > &A) {

    int res = helper(A, 0, 0);
   
    return res;
}


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}