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
#define rep(i,a,b) for(ll i=a;i<=ab;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

//EDITORIAL
string simplifyPath(string path) {
    vector<string>   nameVect;
            string name;

            path.push_back('/');

            for (int i = 0; i < path.size(); i++) {
                if (path[i] == '/') {
                    if (name.size() == 0) continue;
                    if (name == "..") {     //special case 1：double dot，pop dir
                        if (nameVect.size() > 0) nameVect.pop_back();
                    } else if (name == ".") {//special case 2:singel dot，don`t push
                    } else {          
                        nameVect.push_back(name);
                    }
                    name.clear();
                } else {
                    name.push_back(path[i]);//record the name
                }
            }

            string result;
            if (nameVect.empty()) return "/";
            for (int i = 0; i < nameVect.size(); i++) {
                result.append("/" + nameVect[i]);
            }
            return result;
}

/*
string simplifyPath(string A) {
    
    if(A.length() == 0 || A.length() == 1)
    return "/";

    ll n = A.length();

    stack<char> s;
    ll dc = 0;

    fr(i, n){
        if(isalpha(A.at(i)))
        s.push(A.at(i));
        else if(A.at(i) == '.'){
            s.push(A.at(i));
            dc++;
        }
        else if(A.at(i) == '/'){
            if(dc == 0){
                s.push(A.at(i));
            }
            else{

                if(dc == 1){
                    dc--;

                    while(!s.empty() && s.top() != '/')
                    s.pop();
                }
                else if(dc == 2){
                    dc -= 2;

                    while(!s.empty() && !isalpha(s.top()))
                    s.pop();

                    if(!s.empty())
                    s.pop();
                }
            }
        }


    }

    string rem = "";

    while(!s.empty()){
        rem += s.top();
        s.pop();
    }

    reverse(all(rem));

    if(rem.length() == 0)
    rem += '/';
    else if(rem.at(rem.length() - 1) == '/')
    rem = rem.substr(0, rem.length()-1);

    

    return rem;
}
*/
//     /a/./b/../../c/

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}