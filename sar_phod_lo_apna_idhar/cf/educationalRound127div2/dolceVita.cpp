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


/*
1671C - Dolce Vita
Firstly, note that if we want to buy as many packs as possible, then it's optimal to buy the cheapest packs. In other words, if we sort all packs, we'll always buy a prefix of array a.

Next, note that each day we buy some number of packs i∈[1,n], so, instead of iterating through the days, we can iterate through the number of packs i and for each i calculate the number of days we'll buy exactly i packs.

Since the prices increasing and at day k+1 the price is ai+k, then exists last day ki+1 such that as days 1,2,…,ki+1 we could buy i packs and at days ki+2,ki+3,… we can't. And we can find ki as maximum possible integer solution to inequation (a1+ki)+⋯+(ai+ki)≤x or ki=⌊x−(a1+⋯+ai)i⌋.

We can calculate all ki using prefix sums a1+⋯+ai in linear time. As a result, we buy

n packs in days (0,k1+1]; n⋅(k1+1) in total;
n−1 packs in days (k1+1,k2+1]; (n−1)⋅(k2−k1) in total;
n−2 packs in days (k2+1,k3+1]; (n−2)⋅(k3−k2) in total and so on.
The resulting complexity is O(nlogn) because of sort.
*/

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}