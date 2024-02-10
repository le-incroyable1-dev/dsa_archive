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
        if(A.empty()) return 0;
        int N = A.size() - 1;
        sort(A.begin(), A.end());

        // We are doing A[j] - A[i]. So if diff < B we must inc A[j]. So j++
        //And if diff > B we should i ++
        //Takes care of both cases : B +ve and -ve
        int i = 0, j = 1, diff = 0;
        while(i <= N && j <=N){
            diff = A[j] - A[i];
            if(i != j && diff == B) return 1;
            else if(diff < B) j++;
            else i++;
        }
        return 0;
        
    }

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}

//5 478 358 -38 -536 705 
//320

/*
42 -533 -666 -500 169 724 478 358 -38 -536 705 -855 281 -173 961 -509 -5 942 -173 436 -609 -396 902 -847 -708 -618 421 -284 718 895 447 726 -229 538 869 912 667 -701 35 894 -297 811 322 
369



*/