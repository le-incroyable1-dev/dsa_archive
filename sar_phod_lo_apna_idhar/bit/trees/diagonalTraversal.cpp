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
#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The idea is to use map. We use different slope distances and use them as key in map. Value in map is vector (or dynamic array) of nodes. We traverse the tree to store values in map. Once map is built, we print contents of it.

// Suppose slope at current node is x then:
// a) The slope of it’s right child remains same i.e x
// b) The slope of it’s left child becomes x + 1

// As the order in the output matters so we have to move in the pre-order traversal format in the tree A i.e
// 1)Process the root push root to map[slope(root)].push(root)
// 2)Go to left child
// 3)Go to right child
// Keep repeating the above steps until the whole tree is traversed.

// Time Complexity : O(N)
// Space Complexity : O(N)
//17 1 2 3 -1 5 4 -1 6 7 -1 -1 -1 8 -1 -1 -1 -1
