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


unsigned int reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    fr(i, 16){
        unsigned int temp = A;
        int bit1, bit2;

        unsigned int t1 = pow(2, i);
        unsigned int t = temp&t1;

        if(t == t1)
        bit1 = 1;
        else
        bit1 = 0;

        //cout << (unsigned int)temp&t1 << " " << bit1 << endl;

        unsigned int t2 = pow(2, 31-i);
        t = temp&t2;


        temp = A;

        if(t == t2)
        bit2 = 1;
        else
        bit2 = 0;

        //cout << (unsigned int)temp&t2 << " " << bit2 << endl;

        if(bit1 != bit2){
            temp = pow(2, i);
            A = A^temp;

            temp = pow(2, 31-i);
            A = A^temp;
        }

        continue;
    }

    return A;
}
