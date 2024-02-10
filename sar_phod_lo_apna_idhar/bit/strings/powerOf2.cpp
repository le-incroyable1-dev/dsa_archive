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



//ekdum jaise division krte vaise kia hai bkl

string divByTwo(string A)
{
    string ans = "";
    
    int i =0;
    int c;
    int r = 0;
    while(A[i] == '0')
        i++;
    while(A[i] != '\0')
    {
        c = (10 * r) + (A[i] - '0');
        r = c % 2;
        ans.push_back((c/2) + '0');
        i++;
    }
    return ans;

}

int power(string A) 
{
    int len = A.length();
    if((A[A.length()-1]-'0')%2 != 0)    return 0;
    
    while(!(A.length() == 1  && A[0] == '1'))
    {
        
        if((A[A.length()-1]-'0')%2 != 0)    return 0;
        A = divByTwo(A);
    }
    return 1;
}


/* INCORRECT
int countDigit(long long n) {
  return floor(log10(n) + 1);
}


int power(string A) {

    ll n = A.length();

    if(n == 1)
    return stoi(string(1,A.at(0)))%2==0;

    string sub1 = A.substr(0, n/2);
    string sub2 = A.substr(ceil(n/2), n - ceil(n/2));

    string postsub = "1";

    for(int i = 0; i < n-ceil(n/2); i++)
    postsub += "0";

    //cout << sub1 << " " << postsub << " " << sub2 << endl;

    char* endptr = NULL;
    ld p11 = strtoll(sub1.c_str(), &endptr, 10);

    endptr = NULL;
    ld p12 = strtoll(postsub.c_str(), &endptr, 10);

    endptr = NULL;
    ld p2 = strtoll(sub2.c_str(), &endptr, 10);

    //cout << p11 << " " << p12 << " " << p2 << endl;

    int ans = 0;

    //cout << endl << endl;

    ld sum = -1;
    bool flag = true;

    while(sum > 0 || flag){

        //p11 = p11/2;
        flag = false;
        p12 = p12/2;
        p2 = p2/2;

        ans++;
        //cout << countDigit(p12);
        if(countDigit(p12) < 32){
            ld sum1 = p11 * p12;
            ld sum2 = p2;

            
            sum = sum1 + sum2;
            //cout << ans << sum1 << sum2 << sum << endl << endl;
            if(sum == 1)
            break;

        }
    }

    if(sum == 1)
    return 1;
    else
    return 0;
}
*/

