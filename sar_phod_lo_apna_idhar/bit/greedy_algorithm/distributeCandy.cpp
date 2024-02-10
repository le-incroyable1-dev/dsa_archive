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
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int candy(vector<int> &A) {
    int N = A.size();
    vector<int> left(N, 1); // all elements have 1(satisfy condt 1)
    for(int i = 1; i<N; i++){
        // if a rating is more than rating on its left, inc candy of said rating
        // by 1 more than no. of candy on left
        if(A[i] > A[i-1]) left[i] = left[i-1]+1;
    }
    vector<int> right(N,1);
    for(int i = N-2; i>=0; i--){
        // if a rating is more than rating on its right, inc candy of said rating
        // by 1 more than no. of candy on right
        if(A[i] > A[i+1]) right[i] = right[i+1]+1;
    }
    int total = 0;
    for(int i = 0; i<N; i++){
        // max of left2right and right2left candies will satisy condt 2(more candy than
        // both neighbours if higher rating)
        total += max(left[i], right[i]);
    }
    return total;
}