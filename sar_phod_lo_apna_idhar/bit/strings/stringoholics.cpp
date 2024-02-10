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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 

long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll ret(ll n){
    ll k = 1;

    while(k <= n){

        ll sum = (k*(k+1))/2;
        
        if(sum%n == 0)
        break;
        
        k++;
    }

    return k;
}


//INCOMPLETE
int /*Solution::*/solve(vector<string> &A) {

    ll n = A.size();

    ll ans = 1;

    fr(i, n){
        string cur = A[i];
        string ns = cur + cur;

        string cut = ns.substr(1, ns.size()-2);

        if(cur.length() == 1){
            ans = lcm(ans, 1);
            continue;
        }
        else if(cur.length() == 2){
            if(cur[0] == cur[1])
            ans = lcm(ans, 1);
            else
            ans = lcm(ans, ret((ll)2));
            
            continue;
        }

        if(cut.find(cur) == -1)
        ans = lcm(ans, ret((ll)cur.length()));
        else{
            ll index = cut.find(cur);
            string head = ns.substr(0, index);
            string rear = ns.substr(index + cur.size());

            if(head+rear == cur)
            ans = lcm(ans, ret((ll)head.length()));
            else
            ans = lcm(ans, ret((ll)cur.length()));
        }
    }

    if(ans > INT_MAX)
    return INT_MAX;
    else
    return ans;

}


/*
With respect to a single string, the total number of bits rotated after N operations is 1+2+3+….+N which is (N*(N+1))/2.
We get back the original string only when the total number of rotated bits is a multiple of the length 
of the string S(LEN).

This can be done in O(N) time for each string (Summation of length of all strings is <= 1e6), by 
finding all (N(N+1))/2 where N starts from 1 and goes upto (2LEN-1).

But there is a catch, this wont always give you the minimum number of operations.
Its possible that during rotation, you can get the original string before the number of bits rotated 
is a multiple of LEN.

Example: S=> 100100
Here, in 2 operations, we get the original string back.
This takes place because the string is made up of recurring substrings.

*SIGMA MOVE*

Assume string A to be 100
S => A
Hence, over here our length S of string is the *length of recurring substring A*, so N*(N+1)/2 should 
be a multiple of length of A.

*BOOM*

Length of recurring substring can easily be found out using KMP algorithm in O(N) time complexity for each string.
https://www.interviewbit.com/blog/kmp-algorithm-pattern-search/

Find the minimum number of operations for each string, and take the LCM of all these values to get the answer.
Handling of overflow for LCM should be handled by breaking the number down into factors, and then 
taking LCM (Not needed for languages that don’t have integer limit).

Hence total time complexity is O(N).
*/

/*
//BIG F TLE :(

string rotateByk(string s, ll k){
    while(k--){
        s = s.substr(1, s.size()-1) + string(1, s.at(0));
    }

    return s;
}

// Recursive function to return gcd of a and b
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int solve(vector<string> &A) {

    if(A.size() == 0)
    return 0;

    if(A.size() == 1)
    return 1;

    
    ll mint = 1;
    ll csum = 0;
    ll k = 1;
    //vector<int> sumsToN;

    ll n = A.size();

    sort(A.begin(), A.end());

    for(ll i = 0; i < n; i++){
        ll len = A.at(i).length();

        //ll t = 0;

        if(csum!=0 && csum % len == 0){
            continue;
        }

        csum += k;
        

        while(csum % len != 0){
            k++;
            csum += k;
        }

        //cout << A.at(i) << " " << k << endl;

        string s = A.at(i);
        reverse(s.begin(), s.end());

        if(s == A.at(i)){
            ll a = 1;
            
            //IDR SE HI TLE AA RHA :(
            while(rotateByk(s, a) != A.at(i)){
                s = rotateByk(s, a);
                a++;
            }

            k = a;
        }

        mint = lcm(k, mint);

        cout << A.at(i) << " " << k << " " << mint << endl;
        k++;
    }

    return (int)(mint%MOD);
}

*/