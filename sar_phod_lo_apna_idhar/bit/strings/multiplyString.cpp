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

string multiply(string A, string B) {
    int n = A.length(),m = B.length();
    string res(n+m,'0');

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int num = (A[i] - '0') * (B[j] - '0') + res[i+j+1] - '0';
            res[i+j+1] = num%10 + '0';
            res[i+j] += num/10;
        }
    }

    for(int i=0;i<res.length();i++) 
    if(res[i] != '0') return res.substr(i);
    
    return "0";
}



/*

//TLE :(
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

string multiplyBy(string A, int b){

    ll n = A.length();

    int carry = 0;
    //''int num = 

    string ans = "";

    per(i, n-1, 0){
        int num = stoi(string(1, A.at(i)));

        int cur = (num*b + carry)%10;
        carry = (num*b + carry)/10;

        ans += to_string(cur);
    }

    if(carry != 0)
    ans += to_string(carry);

    reverse(all(ans));

    return ans;

}

string addString(string A, string B){
    string l, s;

    if(A.length() > B.length()){
        l = A;
        s = B;
    }
    else{
        l = B;
        s = A;
    }

    ll n = l.length();
    ll m = s.length();

    ll diff = n - m;

    string pre = "";

    fr(i, diff)
    pre += "0";

    pre += s;
    s = pre;

    ll k = n-1;

    string add = "";
    int carry = 0;

    //cout << l << " " << s << endl;

    while(k >= 0){

        int fi = stoi(string(1, l.at(k)));
        int si = stoi(string(1, s.at(k)));

       // cout << fi << " " << si << endl;

        int cur = (fi + si + carry)%10;
        carry = (fi + si + carry)/10;

        //cout << cur << endl;

        add += to_string(cur);
        k--;
    }

    if(carry != 0)
    add += to_string(carry);

    reverse(all(add));

    return add;
}

string multiply(string A, string B) {

    A = trim(A);
    B = trim(B);

    A.erase(0, min(A.find_first_not_of('0'), A.size()-1));
    B.erase(0, min(B.find_first_not_of('0'), B.size()-1));

    //cout << A << endl << B << endl;
    //cout << A.length() << endl << B.length() << endl;

    if((A.length() == 0) || (B.length() == 0))
    return "0";
    
    //cout << "h";

    if(A.length() == 1){

        if(A == "0")
        return A;

    }

    if(B.length() == 1){

        if(B == "0")
        return B;

    }

    //cout << "h";

    string l, s;

    if(A.length() > B.length()){
        l = A;
        s = B;
    }
    else{
        l = B;
        s = A;
    }

    ll n = l.length();
    ll m = s.length();

    ll diff = n - m;

    string pre = "";

    fr(i, diff)
    pre += "0";

    pre += s;
    s = pre;

    ll k = n-1;

    string ans = "";

    while(k >= n-m){

        int c = stoi(string(1,s.at(k)));

        if(c == 0)
        continue;
        
        string cur = "";

        cur = multiplyBy(l, c);
       
        ll k2 = n-k-1;

        while(k2--){
            cur += "0"; 
        }

        //cout << k << endl;
        //cout << cur << endl;

        ans = addString(cur, ans);

        //cout << ans << endl << endl;

        k--;
    }

    ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));
    return ans;
}
*/