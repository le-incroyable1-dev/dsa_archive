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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


string fractionToDecimal(int A, int B) {

    string ans;
    
    string neg = "";
    
    if(B == 0)
    return "inf";
    else if(A == 0)
    return "0";
    
    if((A > 0 && B < 0) || (A < 0 && B > 0)){
        neg += "-";
        A = abs(A);
        B = abs(B);
    }
    
    ld val = (ld)A/(ld)B;
    ld bp = floor(val);
    ld ap = val - bp;

    string bef = to_string((ll)bp);
    string aft = "";

    if(ap == 0.0){
        
        ans = bef;
        return ans;
    }
    else{


        ans += bef;
        ans += ".";

        ll rem = A%B;
        //int digdif = (floor(log10(B)) - floor(log10(rem)));
        //rem *= pow(10, digdif+1);

        /*
        while(digdif){
            aft += "0";
            digdif--;
        }
        */

       bool rep = false;
       unordered_map<int, ll> map;
       rem *= 10;
       map.insert(mp(rem, 0));
       int ind = 0;

       aft += to_string((ll)(rem/B));
       rem = rem%B;
       
       ind++;

       while((rem != 0) && !rep){

        rem *= 10;

        if(map.find(rem) != map.end()){
            ind = map.find(rem)->second;
            rep = true;
            break;
        }
        else
        map.insert(mp(rem, ind));
        
        //ind++;
        if(!rep)
        aft += to_string((ll)(rem/B));
        
        rem = rem%B;

        ind++;

        
       }
       
       if(rep)
       aft = aft.substr(0, ind) + "(" + aft.substr(ind, aft.size()-ind) + ")";
       
       ans += aft;
       ans = neg + ans;
    }
    
    return ans;

}

