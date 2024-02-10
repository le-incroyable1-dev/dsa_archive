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
//#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


 // Definition for singly-linked list.
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

RandomListNode* copyRandomList(RandomListNode *head) {
    if(head == NULL){
        return NULL;
    }

    // Step 1: create a new node for each existing node and join them together 
    // eg: A->B->C will be A->A'->B->B'->C->C'
    RandomListNode* node = head;
    while (node != NULL) {
        RandomListNode* copyNode = new RandomListNode(node->label);
        RandomListNode* nextNode = node->next;
        node->next = copyNode;
        copyNode->next = nextNode;
        node = nextNode;
    }

    // Step2: copy the random links: for each new node n', 
    // n'.random = n.random.next
    node = head;
    while(node != NULL) {
        RandomListNode* copyNode = node->next;
        if(node->random != NULL)
            copyNode->random = node->random->next;
        else
            copyNode->random = NULL;
        node = copyNode->next;
    }

    // Step3: detach the list: 
    // basically n.next = n.next.next; n'.next = n'.next.next
    node = head;
    RandomListNode* copyNode = node->next;
    RandomListNode* copyHead = head->next;
    while(copyNode != NULL && node != NULL) {
        node->next = node->next->next;
        if (copyNode->next == NULL) {
            break;
        }
        copyNode->next = copyNode->next->next;

        copyNode = copyNode->next;
        node = node->next;
    }

    return copyHead;
}