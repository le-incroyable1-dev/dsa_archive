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


vector<string> prettyJSON(string A) {

    ll n = A.length();

    if(n < 2){
        vector<string> v;
        v.pb(A);
        return v;
    }

    vector<string> v;
    string s;
    ll tabs = 0;

    fr(i, n){

        char cur = A.at(i);
        char next;

        if(i < n-1){
            next = A.at(i+1);
        }

        if(cur == ','){
            s+=string(1,cur);
            v.pb(s);
            s = "";

            for(int i = 0; i < tabs; i++)
            s+="\t";
        }
        else if(next == '{' || next == '['){
            
            s+=string(1, cur);
            v.pb(s);
            s="";

            if(cur == '{' || cur == '['){
            tabs++;
            s = "";
            }


            for(int i = 0; i < tabs; i++)
            s+="\t";
        }
        else if(next == '}' || next == ']'){
            s+=string(1, cur);
            v.pb(s);
            tabs--;
            s="";

            if(cur == '{' || cur == '['){
            tabs++;
            s = "";
            }

            for(int i = 0; i < tabs; i++)
            s+="\t";
        }
        else if(cur == '{' || cur == '['){
            s+=string(1, cur);
            v.pb(s);
            tabs++;
            s = "";

            for(int i = 0; i < tabs; i++)
            s+="\t";
        }
        else if(cur == '}' || cur == ']'){
            s+=string(1, cur);
            if(next != ',')
            v.pb(s);
            //tabs--;

            s = "";

            for(int i = 0; i < tabs; i++)
            s+="\t";
        }
        else{
            s+=string(1, cur);
            //v.pb(s);
        }
    }

    return v;
}



int main(void){
    fast;

    string A;
    getline(cin, A);

    vector<string> v = prettyJSON(A);

    for(auto s : v)
    cout << s << endl;

}

/*
{"attributes":[{"nm":"ACCOUNT","lv":[{"v":{"Id":null,"State":null},"vt":"java.util.Map","cn":1}],"vt":"java.util.Map","status":"SUCCESS","lmd":13585},{"nm":"PROFILE","lv":[{"v":{"Party":null,"Ads":null},"vt":"java.util.Map","cn":2}],"vt":"java.util.Map","status":"SUCCESS","lmd":41962}]}
*/

/*
expected

{ ## 	"attributes": ## 	[ ## 		{ ## 			"nm":"ACCOUNT", ## 			"lv": ## 			[ ## 				{ ## 					"v": ## 					{ ## 						"Id":null, ## 						"State":null ## 					}, ## 					"vt":"java.util.Map", ## 					"cn":1 ## 				} ## 			], ## 			"vt":"java.util.Map", ## 			"status":"SUCCESS", ## 			"lmd":13585 ## 		}, ## 		{ ## 			"nm":"PROFILE", ## 			"lv": ## 			[ ## 				{ ## 					"v": ## 					{ ## 						"Party":null, ## 						"Ads":null ## 					}, ## 					"vt":"java.util.Map", ## 					"cn":2 ## 				} ## 			], ## 			"vt":"java.util.Map", ## 			"status":"SUCCESS", ## 			"lmd":41962 ## 		} ## 	] ## } ## 
*/

/*

*/
