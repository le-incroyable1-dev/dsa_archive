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
 


void helper(tn A, int &ct, int B, int &ans){

    if(A->left == NULL && A->right == NULL){
        ct++;
        
        if(ct == B){
            ans = A->val;
            //cout << ans << endl;
            return;
        }
        
        return;
    }
    else if(A->left == NULL){
        ct++;

        if(ct == B){
            ans = A->val;
            //cout << ans << endl;
            return;
        }
        else
        helper(A->right, ct, B, ans);
        
        return;

    }
    else if(A->right == NULL){
        helper(A->left, ct, B, ans);

        ct++;
        if(ct == B){
            ans = A->val;
            //cout << ans << endl;
            return;
        }
        
        return;
    }
    else{
        helper(A->left, ct, B, ans);
        ct++;
        if(ct == B){
            ans = A->val;
            //cout << ans << endl;
            return;
        }
        helper(A->right, ct, B, ans);
        
        return;
    }
    
    return;
}

int kthsmallest(TreeNode* A, int B) {

    int ans;
    int ct = 0;
    helper(A, ct, B, ans);
    
    return ans;

}

int main(){

    tn A = new TreeNode(4);
    tn B = new TreeNode(3);
    tn C = new TreeNode(5);

    A->left = B;
    A->right = C;

    cout << kthsmallest(A, 3);

    return 0;
}