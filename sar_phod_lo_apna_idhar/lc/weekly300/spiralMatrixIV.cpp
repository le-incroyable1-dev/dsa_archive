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


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:


    void helper(vvi &mat, int s, int m, int n, ListNode* head){

        if(m <= 0 || n <= 0)
        return;

        if(head == NULL)
        return;

        rep(i, s, n+s-1){
            if(head == NULL)
            return;

            mat[s][i] = head->val;
            head = head->next;
        }

        rep(i, s+1, m+s-1){
            if(head == NULL)
            return;

            mat[i][n+s-1] = head->val;
            head = head->next;
        }

        per(i, n+s-2, s){
            if(head == NULL)
            return;

            mat[m+s-1][i] = head->val;
            head = head->next;
        }

        per(i, m+s-2, s+1){
            if(head == NULL)
            return;

            mat[i][s] = head->val;
            head = head->next;
        }

        helper(mat, s+1, m-2, n-2, head);
        return;
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> mat(m , vector<int>(n, -1));
        helper(mat, 0, m, n, head);
        return mat;
    }
};