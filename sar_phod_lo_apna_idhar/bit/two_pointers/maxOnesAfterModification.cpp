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
#define vpi vector< pii >c
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


int solve(vector<int> &A, int B) {
 int n=A.size();
    int l=0, i=0, count=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count++;
        }
        while(count>B){
            if(A[l]==0)count--;
            l++;
        }
        ans=max(ans, i-l+1);
    }
    return ans;
}


/*
int numZeros(vector<int> A, ll l, ll r){

    int zeros = 0;
    
    while(l <= r){
        if(A.at(l) == 0)
        zeros++;

        l++;
    }

    return zeros;
}

int solve(vector<int> &A, int B) {

    ll n = A.size();

    if(n == 0)
    return 0;

    if(n == 1){
        if(A.at(0) == 1)
        return 1;
        else{
            if(B >= 1)
            return 1;
            else 
            return 0;
        }
    }

    ll l = 0;
    ll r = 0;

    int ans = INT_MIN;

    while(l < n && r < n){
        while(r < n && numZeros(A,l,r) <= B){
            r++;
        }

        int len = r-l;

        if(len > ans)
        ans = len;

        l = r;
    }
    return ans;
}
*/
/*
10 0 0 0 0 0 1 1 1 1 1 
2
*/


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}