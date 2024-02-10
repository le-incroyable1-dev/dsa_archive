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


void inorderFill(TreeNode* root, vi &v){
    if(root==NULL){
        return ;
    }
    inorderFill(root->left, v);
    v.pb(root->val);
    inorderFill(root->right, v);
    
    return ;
}
 
int t2Sum(TreeNode* A, int B) {

    vi bst;
    inorderFill(A, bst);

    ll n = bst.size();

    if(n < 2)
    return 0;

    unordered_map<ll, ll> mapp;
    unordered_map<ll, ll>::iterator itr;

    fr(i, n){
        itr = mapp.find(bst[i]);

        if(itr == mapp.end())
        mapp.insert(mp(bst[i], 1));
        else
        ++itr->second;
    }

    fr(i, n){

        itr = mapp.find(bst[i]);
        itr->second--;

        if(itr->second == 0)
        mapp.erase(itr);

        ll req = B-bst[i];

        itr = mapp.find(req);
        if(itr != mapp.end())
        return 1; 
    }

    return 0;
}

/*
//using two pointers
vector<int>res;
unordered_map<int,int>m;
void dfs(TreeNode* x)
{
    if(x==NULL)
    {
        return ;
    }
    else 
    {
        dfs(x->left);
        res.push_back(x->val);
        dfs(x->right);
    }
}
int Solution::t2Sum(TreeNode* A, int B) {
    m.clear();res.clear();
    dfs(A);
    // for(auto u:m)
    // {
    //     if(m.find(B-u.first)!=m.end()&&(2*u.first!=B))
    //     {
    //         // return u.first;
    //         return 1;
    //     }
    int n=res.size();
    int j=n-1;
    int i=0;
    while(i<j)
    {
        if((res[i]+res[j])>B)
        j--;
        else if(res[i]+res[j]<B)
        i++;
        else return 1;
    }
    return 0;
    // }
    return 0;
}
*/
