
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
#define zero '0'
#define one '1'
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};




char addBin(char a, char b, int &carry){

    int ai = a - '0';
    int bi = b - '0';

    int sum = (ai+bi+carry)%2;
    carry = (ai+bi+carry)/2;

    return '0' + sum;
}

    


string addBinary(string A, string B) {

    ll n = A.length();
    ll m = B.length();

    if(n == 0)
    return B;
    else if(m == 0)
    return A;

    int carry = 0;
    string res = "";

    if(n > m){
        int r = n - m;
        string pre;
        fr(i, r){
            pre += string(1, zero);
        }

        B = pre + B;
    }
    else if(m > n){
        int r = m - n;
        string pre;
        fr(i, r){
            pre += string(1, zero);
        }

        A = pre + A;
    }

    ll i = A.length()- 1;

    //cout << A << endl << B << endl;

    while(i >= 0){
        
        char c1 = A.at(i);
        char c2 = B.at(i);

        

        char cur = addBin(c1, c2, carry);
        res += string(1, cur);

        //cout << c1 << " " << c2 << " " << cur << " " << carry << endl;

        i--;
    }

    //cout << res << endl << carry << endl;

    if(carry == 1)
    res += string(1, one);

    reverse(res.begin(), res.end());

    return res;


}
