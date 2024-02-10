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
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//INCOMPLETE

int depth(tn A){
    if(A == NULL)
    return 0;

    int ld = 0;
    int rd = 0;

    ld = 1+depth(A->left);
    rd = 1+depth(A->right);

    return max(ld, rd);
}

int calcAns(tn A, int B, unordered_map<tn, tn> &mapp){
    
    if(mapp.find(A) == mapp.end()){
        tn node = NULL;

        if(A->left && A->left->val != B)
        node = A->left;
        else if(A->right && A->right->val != B)
        node = A->right;

        return depth(node);
    }
    else{
        unordered_map<tn, tn>::iterator itr;
        itr = mapp.find(A);

        tn parent = itr->second;
        tn node = NULL;

        if(A->left && A->left->val != B)
        node = A->left;
        else if(A->right && A->right->val != B)
        node = A->right;

        return depth(node)+calcAns(parent, A->val, mapp);
        
    }

}

int solve(TreeNode* A, int B) {

    if(A->val == B)
    return 1;

    unordered_map<tn, tn> mapp;
    queue<tn> nodes;
    nodes.push(A);
    tn par;

    while(nodes.size()){

        tn cur = nodes.front();
        nodes.pop();

        if(cur->left){
            if(cur->left->val == B){
                par = cur;
                break;
            }

            mapp.insert(mp(cur->left, cur));
            nodes.push(cur->left);
        }

        if(cur->right){
            if(cur->right->val == B){
                par = cur;
                break;
            }

            mapp.insert(mp(cur->right, cur));
            nodes.push(cur->right);
        }
    }

    return 1+calcAns(par, B, mapp);

}
