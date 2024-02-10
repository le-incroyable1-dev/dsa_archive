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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


const std::string WHITESPACEL = " \n\r\t\f\v";
const std::string WHITESPACER = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACEL);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACER);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

ll toInt(string s){

    ll n = s.length();

    ll num = 0;
    ll p = 0;

    per(i, n-1, 0){
        //cout << s.at(i)-48 << endl;
        if( num + pow(10,p)*(s.at(i)-48) > LLONG_MAX)
        return LLONG_MAX;

        num += pow(10, p) * (s.at(i) - 48);
        //cout << num << endl;
        p++;
    }

    return num;
}

int atoi(const string A) {

    ll n = A.length();

    if(n == 0)
    return 0;

    string s = A;
    s = trim(s);

    n = s.length();

    if(n == 0)
    return 0;

    bool pos = true;

    string num = "";

    fr(i , n){

        char c = s.at(i);

        if(c == '+' || c == '-'){

            if(i == 0){
                if(c == '-')
                pos = false;
                else
                pos = true;
            }
            else
            return 0;
        }
        else if(c >= '0' && c <= '9'){
            num += string(1, c);
        }
        else{
            if(num == "")
            return 0;

            break;
        }

    }

    //cout << num << endl;

    ll res = toInt(num);

    //cout << res << endl;

    if(pos){
        if(res > INT_MAX)
        return INT_MAX;
    }
    else{
        if((-1)*res < INT_MIN)
        return INT_MIN;
    }

    if(pos)
    return (int)res;
    else
    return (-1)*(int)res;
}
