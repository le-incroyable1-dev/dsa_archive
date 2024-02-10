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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int convertStringToInt(string s)
{
    int num = 0;
  
    // convert binary string into integer
    for (int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}
  
//GFG soln
int solve(int n) {
    // base case
    if (n == 1)
        return 1;
    n--;
  
    // stores the binary palindrome string
    queue<string> q;
  
    // add 2nd binary palindrome string
    q.push("11");
  
    // runs till the nth binary palindrome number
    while (!q.empty()) {
        // remove curr binary palindrome string from queue
        string curr = q.front();
        q.pop();
        n--;
  
        // if n==0 then we find the n'th binary palindrome
        // so we return our answer
        if (!n) {
            return convertStringToInt(curr);
        }
  
        int mid = curr.size() / 2;
  
        // if length is even .so it is our first case
        // we have two choices
        if (curr.size() % 2 == 0) {
            string s0 = curr, s1 = curr;
            s0.insert(mid, "0");
            s1.insert(mid, "1");
            q.push(s0);
            q.push(s1);
        }
          
        // if length is odd .so it is our second case
        // we have only one choice
        else {
            string ch(1, curr[mid]);
            string temp = curr;
            temp.insert(mid, ch);
            q.push(temp);
        }
    }
  
    return 0;
}

/*

We can divide the set of palindrome numbers into some groups.
n-th group will have (2^(n-1) + 2^n = 3 * 2 ^(n-1) ) number of binary palindromes

?!?! WTF

*/
/*
int solve(int A) {

}
*/

int main(void){
    
    fast;

    test(t){
        //solve();
    }
    
}

