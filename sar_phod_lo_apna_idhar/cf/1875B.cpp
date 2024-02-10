//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
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


void sol(){
    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> s1, s2;
    fr(i, n){ int x; cin >> x; s1.insert(x); }
    fr(i, m){ int x; cin >> x; s2.insert(x); }


    multiset<int>::iterator itr1 = s1.end(); itr1--;
    multiset<int>::iterator itr2 = s2.end(); itr2--;
    int l1 = *itr1; int l2 = *itr2;

    while(*itr1 == *itr2){
        s1.erase(*itr1); s2.erase(*itr2);
        if(s1.empty() || s2.empty()) break;
        itr1 = s1.end(); itr1--; itr2 = s2.end(); itr2--;
        l1 = *itr1; l2 = *itr2;
    }

    int res = 0;
    multiset<int> ss1 = s1;
    multiset<int> ss2 = s2;

    int rounds = 0;
    do{
        ++rounds;
        itr1 = ss1.end(); itr1--; itr2 = ss2.end(); itr2--;
        l1 = *itr1; l2 = *itr2;

        if(l1 < l2)
    }while(!(ss1 == s1 && ss2 == s2));
}



int main(void){
    fast;
    test(t){
        sol();
    } 
}