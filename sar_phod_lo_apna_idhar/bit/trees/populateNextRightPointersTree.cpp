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
#define tn TreeNode*
#define tln TreeLinkNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


 //Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


// solution in constant space

void connect(TreeLinkNode* A) {

    
}



// O(n) space required
/*
void helper(tln A, vector<tln> &v){

    if(A == NULL)
    return;

    queue<tln> q;
    q.push(A);
    q.push(NULL);

    while(!q.empty()){
        tln cur = q.front();
        q.pop();

        if(cur == NULL){
            v.pb(NULL);

            if(q.size() == 0)
            break;
            else
            q.push(NULL);
        }
        else{
            v.pb(cur);

            if(cur->left)
            q.push(cur->left);

            if(cur->right)
            q.push(cur->right);
        }
    }
    return;
}


void connect(TreeLinkNode* A) {

    if(A == NULL)
    return;

    vector<tln> v;
    helper(A, v);

    ll n = v.size();

    fr(i, n){
        if(v[i] == NULL)
        continue;
        else if(i+1 < n){
            if(v[i+1] == NULL)
            v[i]->next = NULL;
            else
            v[i]->next = v[i+1];
        }
    }

    v.clear();

    return;
}

*/


/*
15 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
5 3 6 NULL 7 NULL NULL 
*/