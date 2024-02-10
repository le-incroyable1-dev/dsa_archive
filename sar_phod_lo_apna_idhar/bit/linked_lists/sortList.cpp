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



 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ln SortedMerge(ln a, ln b)
{
    ln result = NULL;
     
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
     
    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}


ListNode* sortList(ListNode* A) {

    if(A == NULL || A->next == NULL)
    return A;

    ll len = 0;

    ln temp = A;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }

    ll len1 = len/2;
    ll len2 = len-len1;
    delete temp;


    ln l1 = A;

    fr(i, len1-1){
        l1 = l1->next;
    }

    ln l2 = l1->next;
    l1->next = NULL;

    ln list1 = sortList(A);
    ln list2 = sortList(l2);

    ln res = SortedMerge(list1, list2);

    return res;
}


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}