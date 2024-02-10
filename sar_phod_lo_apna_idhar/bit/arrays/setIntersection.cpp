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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


//9 2 3 9 3 5 19 20 3 6 9 16 10 14 9 17 1 3 4 16 



bool comp(const vector < int > & A,
    const vector < int > & B) {
    if (A[1] != B[1])
        return A[1] < B[1];
    return A[0] < B[0];
}

int setIntersection(vector < vector < int > > & A) {
    int n = A.size();
    sort(A.begin(), A.end(), comp);
    vector < int > res;
    res.push_back(A[0][1] - 1);
    res.push_back(A[0][1]);
    for (int i = 1; i < n; i++) {
        int start = A[i][0];
        int end = A[i][1];
        int size = res.size();
        int last = res[size - 1];
        int secondLast = res[size - 2];
        if (start > last) {
            res.push_back(end - 1);
            res.push_back(end);
        } else if (start == last) {
            res.push_back(end);
        } else if (start > secondLast) {
            res.push_back(end);
        }
    }
    return res.size();
}