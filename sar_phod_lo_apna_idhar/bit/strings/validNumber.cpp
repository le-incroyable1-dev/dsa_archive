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

#define isNum(x) x >= '0' && x <= '9'
#define isDot(x) x == '.'
#define isE(x) x == 'e'

#define isNum(x) x >= '0' && x <= '9'
#define isDot(x) x == '.'
#define isE(x) x == 'e'
const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int isNumber(const string A) {

    ll n = A.length();

    if(n == 0)
    return 0;

    //A.at(0) = 1;

    string cur = "";
    bool efound = false;
    bool dotfound = false;
    bool init = true;

    string s = A;
    s = trim(s);

    n = s.length();

    fr(i, n){
        char c = s.at(i);

        if(c == ' '){
            if(init)
            continue;
            else
            return 0;
        }

        if(isNum(c)){
            init = false;
            cur += string(1, c);
        }
        else if(isE(c)){

            if(cur == "")
            return 0;

            init = false;
            if(efound){

                if(cur.find('.') != string::npos)
                return 0;
            
            }

            efound = true;
            //cout << cur << endl;
            cur = "";
        } 
        else if(isDot(c)){

            init = false;

            if(efound)
            return 0;

            if(dotfound)
            return 0;

            dotfound = true;
            //cout << cur << endl;
            cur = "";
        }
        else if(c == '-'){

            init = false;

            if(cur != "")
            return 0;

            cur += string(1, c);
        }
        else
        return 0;
    }

    if(init || cur == "")
    return 0;

    return 1;
}


//32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609