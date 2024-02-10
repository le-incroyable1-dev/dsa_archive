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
#define vi vector< ll >
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
#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


void swap(int&a, int &b){
    int temp = a;
    a = b;
    b = a;
}

 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* insertionSortList(ListNode* A) {

    if(A == NULL || A->next == NULL)
    return A;

    ln prev = A;
    ln cur = A->next;

    while(cur != NULL){

        if(cur->val <= prev->val){
            //swap(cur->val, prev->val);

            int vc = cur->val;
            ln temp = prev;
            int v = temp->val;

            while(temp != cur){
                int t = temp->next->val;
                temp->next->val = v;
                v = t;
                temp = temp->next;
            }

            prev->val = vc;
        }

        cur = cur->next;

        if(cur == NULL)
        continue;

        prev = A;

        if(prev->val > cur->val)
        continue;
        
        while(prev->val < cur->val){
            prev = prev->next;
        }
        
    }

    return A;

}


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}