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
#define rep(i,a,b) for(ll i=a;i<=ab;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 /*
Problem Description


Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.

Example:

Input: 


              ______
             |     |
             \/    |
    1 -> 2 -> 3 -> 4


Return the node corresponding to node 3.


Constant additional space : 2 pointer approach ( Floyd’s Cycle-Finding Algorithm ) :
What if you have 2 pointers which are going at different speed. For arguments sake, lets just say one pointer is going at double the speed of the other.
Would they meet if there is a cycle ? Are they guaranteed to meet if there is a cycle ?
What happens if there is no cycle ?

Once you detect a cycle, think about finding the starting point.


 */


//Solution using linear additional space
 ListNode* detectCycle(ListNode* A) {
   
    
    map<ListNode*, int> mp;

    while(A!=NULL){

        if(mp[A] != 0){
            return A;
        }
        
         mp[A] = 1;
         A= A->next;
    }
    
    
    return NULL;
}

//Editorial, constant additional space
ListNode* detectCycle2(ListNode* A) {
    ListNode *hare = A, *turtle = A;
    int loopLength = 0;
    
    while (hare && turtle && hare->next) {
        turtle = turtle->next;
        hare = hare->next->next;
        if (hare == turtle) {
            // Found loop
            while (hare->next != turtle) {
                hare = hare->next;
                ++loopLength;
            }
            ++loopLength;
            // Determined the size of cycle
            hare = A;
            while (loopLength > 0) {
                hare = hare->next;
                --loopLength;
            }

            /*
            Fix one pointer on the head, and another pointer to kth node from head.
            Now move them simulataneously one step at a time. They will meet at the starting point of the cycle.
            */

            while (A != hare) {
                A = A->next;
                hare = hare->next;
            }

            // They meet at the starting point
            return A;
        }
    }
    return NULL;
}

/*
What happens with the 2 pointer approach ?

Method 1 :
If you detect a cycle, the meeting point is definitely a point within the cycle.

Can you determine the size of the cycle ? ( Easy ) Let the size be k.
Fix one pointer on the head, and another pointer to kth node from head.
Now move them simulataneously one step at a time. They will meet at the starting point of the cycle.


Method 2 :
This might be slightly more complicated. It involves a bit of maths and is not as intuitive as method 1.
Suppose the first meet at step k,the distance between the start node of list and the start node of cycle is s, 
and the distance between the start node of cycle and the first meeting node is m.
Then
2k = (s + m + n1r)
2(s + m + n2r) = (s + m + n1r)
s + m = nr where n is an integer.
s = nr - m
s = (r - m) + (n-1)r

So, if we have one pointer on the head and another pointer at the meeting point. Note that since the distance between 
start node of cycle and the first meeting node is m, therefore if the pointer moves (r - m) steps, it will reach the 
start of the cycle. When the pointer at the head moves s steps, the second pointer moves (r-m) + (n-1)r steps which 
both points to the start of the cycle. In other words, both pointers meet first at the start of the cycle.

*/

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}