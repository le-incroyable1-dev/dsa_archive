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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

vector<int> slidingMaximum(const vector<int> &A, int B) {
    vi res;
    ll n = A.size();

    if(B >= A.size()){
        res.pb(*max_element(A.begin(), A.end()));
        return res;
    }

    deque<int> dq;

    


    

    return res;
}

/*
Approach 1 :
The obvious brute force solution with run time complexity of O(nw) is definitely not efficient enough. 
Every time the window is moved, you have to search for a total of w elements in the window.

Approach 2:
A heap data structure quickly comes to mind. We could boost the run time to approximately O(n lg w) 
(Note that I said approximately because the size of the heap changes constantly and averages about w). 
Insert operation takes O(lg w) time, where w is the size of the heap. However, getting the maximum value 
is cheap, it merely takes constant time as the maximum value is always kept in the root (head) of the heap.

As the window slides to the right, some elements in the heap might not be valid anymore 
(range is outside of the current window). How should you remove them? You would need to be 
somewhat careful here. Since you only remove elements that are out of the window’s range, 
you would need to keep track of the elements’ indices too.

Time complexity : O ( n log n ). Not good enough.

Approach 3 :
A double-ended queue should do the trick here.
The double-ended queue is the perfect data structure for this problem. It supports insertion/deletion from 
the front and back. The trick is to find a way such that the largest element in the window would always 
appear in the front of the queue. How would you maintain this requirement as you push and pop elements in and out of the queue?

###############
You might notice that there are some redundant elements in the queue that we shouldn’t even consider about. 
For example, if the current queue has the elements: [10 5 3], and a new element in the window has the element 11. 
Now, we could have emptied the queue without considering elements 10, 5, and 3, and insert only element 11 into the queue.

A natural way most people would think is to try to maintain the queue size the same as the window’s size. 
Try to break away from this thought and try to think outside of the box. Removing redundant elements and 
storing only elements that need to be considered in the queue is the key to achieve the efficient O(n) solution.
###############
*/


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}