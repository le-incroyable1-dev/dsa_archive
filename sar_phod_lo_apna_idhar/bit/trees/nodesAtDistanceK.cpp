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


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

map<TreeNode*, TreeNode*> parent;

TreeNode* target;
vector<int> ans;

void dfs(TreeNode* root, int B){
    if(root->val==B){
        target = root;
    }
    if(root->left!=NULL){
        parent[root->left] = root;
        dfs(root->left, B);
    }
    if(root->right!=NULL){
        parent[root->right] = root;
        dfs(root->right, B);
    }
}

void bfs(int C){
    
    map<TreeNode*, int> depth;
    queue<TreeNode*> q;
    q.push(target);
    depth[target] = 0;
    
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        
        if(parent.find(cur)!=parent.end()){
            TreeNode* t = parent[cur];
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->left!=NULL){
            TreeNode* t = cur->left;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
        
        if(cur->right!=NULL){
            TreeNode* t = cur->right;
            if(depth.find(t)==depth.end() || depth[t]>1+depth[cur]){
                depth[t] = 1+depth[cur];
                if(depth[t]==C){
                    ans.push_back(t->val);
                }
                q.push(t);
            }
        }
    }
}

vector<int> distanceK(TreeNode* A, int B, int C) {
    parent.clear();
    ans.clear();
    dfs(A, B);
    bfs(C);
    return ans;
}
