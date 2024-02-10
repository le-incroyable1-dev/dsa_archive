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


//FASTEST
string convert(string s, int b)
{
    s = trim(s);

    if(b==1)
    return s;

    vector<vector<char>> v(b);

    int i,l=s.length(),f=0,k=0;

    for(i=0;i<l;i++)
    {
        if(f==0)
        {
            v[k].push_back(s[i]);
            k++;
            if(k==b)
            {
                k-=2;
                f=1;
            }
        }
        else
        {
            v[k].push_back(s[i]);
            k--;
            if(k==-1){
                k+=2;
                f=0;
            }
        }
    }


    string w="";
    for(i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            w+=v[i][j];
        }
    }


    return w;
}

int main(){
    string s;
    int b;

    cin >> s >> b;

    cout << convert(s, b);
}