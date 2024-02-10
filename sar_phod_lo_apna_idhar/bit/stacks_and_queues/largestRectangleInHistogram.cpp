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

int largestRectangleArea(vector<int> &A) {

    ll n = A.size();

    if(n == 0)
    return 0;
    else if(n == 1)
    return A[0];

    int mx = n;
    int min_ht = INT_MAX;
    stack<int> s;

    
    
    return mx;
}

/*
//PARTIALLY CORRECT
int largestRectangleArea(vector<int> &A) {

    ll n = A.size();

    if(n == 0)
    return 0;
    else if(n == 1)
    return A[0];

    int mx = n;

    stack<int> s;
    fr(i, n)
    s.push(A[i]);

    while(!s.empty()){
        int cur = s.top();
        int m = cur;
        int w = 0;
        int ar = cur;

        while(!s.empty() && s.top() <= cur){
            m = min(m, s.top());
            w++;
            s.pop();

            if(w*m > ar)
            ar = w*m;
        }

        

        if(ar > mx)
        mx = ar;
    }

    per(i, n-1, 0)
    s.push(A[i]);

    while(!s.empty()){
        int cur = s.top();
        int m = cur;
        int w = 0;
        int ar = cur;

        while(!s.empty() && s.top() <= cur){
            m = min(m, s.top());
            w++;
            s.pop();

            if(w*m > ar)
            ar = w*m;
        }

        if(ar > mx)
        mx = ar;
    }

    return mx;
}
*/

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}