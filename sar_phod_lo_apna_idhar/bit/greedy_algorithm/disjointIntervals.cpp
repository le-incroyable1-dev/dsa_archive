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


/*
To get a disjoint interval, ei < sj
so I need to find minimum possible ei first in order to find the maximal possible subset of disjoint intervals
therefore I sort by the end points
*/

bool compare(vector<int> &v1,vector<int> &v2){
    return v1[1]<v2[1];
}

int solve(vector<vector<int> > &A) {

    ll n = A.size();
    
    if(n == 0)
    return 0;
    else if(n == 1)
    return 1;
    
    sort(A.begin(),A.end(),compare);
    
    int ans=1;
    int temp=A[0][1];
    
    rep(i,1,n-1){
        if(temp<A[i][0]){
            ans++;
            temp=A[i][1];
        }
    }
    return ans;
}

/*
16 2 3 13 7 7 3 10 4 8 7 8 9 12 3 6 7 12 4 10 3 8 5 11 9 10 3 7 4 4 7 15 2 9 
*/