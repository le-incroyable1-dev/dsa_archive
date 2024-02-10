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

bool contains(tn A, int val){
    if(A == NULL)
    return false;

    if(A->val == val)
    return true;
    else
    return (contains(A->left, val) || contains(A->right, val));
}

void storeAns(unordered_map<tn, tn> &mapp, int &ans, tn child, int C){

    if(child == NULL)
    return;

    unordered_map<tn, tn>::iterator itr;
    itr = mapp.find(child);

    if(itr == mapp.end())
    return;

    tn parent = itr->second;
    if(contains(child, C)){
        ans = child->val;
        //or ans = parent->val according to problem's requirement
        return;
    }
    else{
        if(parent->left && parent->left->val != child->val){
            if(contains(parent->left, C)){
                ans = parent->val;
                return;
            }
        }
        else if(parent->right && parent->right->val != child->val){
            if(contains(parent->right, C)){
                ans = parent->val;
                return;
            }
        }
    }

    //if still not found search in upper nodes

    storeAns(mapp, ans, parent, C);
    return;
}

void setup(tn A, int B, int &ans, unordered_map<tn, tn> &mapp, int C){

    if(A == NULL)
    return;
    else if(A->left == NULL && A->right == NULL)
    return;

    bool found = false;
    tn child;

    if(A->left){
        if(A->left->val == B){
            found = true;
            child = A->left;
        }

        mapp.insert(mp(A->left, A));
    }
    
    if(A->right){
        if(A->right->val == B){
            found = true;
            child = A->right;
        }

        mapp.insert(mp(A->right, A));
    }

    if(found){
        storeAns(mapp, ans, child, C);
        return;
    }
    else{
        setup(A->left, B, ans, mapp, C);
        setup(A->right, B, ans, mapp, C);
        return;
    }

}

int lca(TreeNode* A, int B, int C) {

    if(!contains(A, B) || !contains(A, C))
    return -1;

    if(A->val == B || A->val == C)
    return A->val;

    int ans = -1;
    unordered_map<tn, tn> mapp;
    setup(A, B, ans, mapp, C);

    return ans;
}

/*
73 15 20 34 35 5 14 16 26 -1 25 23 -1 30 3 36 -1 -1 7 24 11 32 -1 -1 
21 -1 -1 -1 29 4 9 -1 33 13 -1 -1 -1 -1 22 31 -1 27 19 1 -1 12 18 6 -1 
-1 -1 2 -1 -1 -1 -1 10 -1 -1 -1 -1 8 -1 28 -1 -1 -1 -1 -1 17 -1 -1 -1 -1
33
5

*/