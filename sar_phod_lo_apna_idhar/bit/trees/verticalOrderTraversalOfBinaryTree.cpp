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


vector<vector<int> > verticalOrderTraversal(TreeNode* root) {
    
    unordered_map< int , vector<int>> mp;
    int i=0;
    vector<vector<int>> res;

    if(root==NULL)
    {
    return res;
    }

    if(root->left==NULL && root->right==NULL)
    {
    return {{root->val}};
    }

    // then do the level order traversal

    int mine =0, maxe =0;

    queue< pair< TreeNode* , int>> q;

    q.push({root , 0});

    TreeNode* curr;

    while(!q.empty())
    {
        int sz=q.size();

        while(sz--)
        {
            curr=q.front().first;
            int idx=q.front().second;
            q.pop();

            mine=min(mine , idx);
            maxe=max(maxe , idx);

            mp[idx].push_back(curr->val);

            if(curr->left)
            {
                q.push({curr->left , idx-1});
            }

            if(curr->right)
            {
                q.push({curr->right , idx+ 1});
            }
        }
    }    



    for(int i=mine ;i<=maxe ;i++)
    {
        if(mp.find(i)!=mp.end())
        {
            res.push_back(mp[i]);
        }
    }

    return res;
}

/*
43 460 3871 4698 8399 504 4421 7515 -1 4167 5727 -1 -1 3096 434 7389 2667 5661 1969 7815 4292 3006 9750 6693 -1 6906 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

*/

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}