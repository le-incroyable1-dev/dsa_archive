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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};
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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


int solve(vector<int> &A) {

    
}


/*
void swap(pair<int, int> &x, pair<int, int> &y)
{
    if(y.second <= x.second)
    {
        int temp = y.first;
        y.first = x.first;
        x.first = temp;
    }
}


int solve(vector<int> &A) {

    pair<int, int> n1;
    n1.first = A.at(0);
    n1.second = 0;

    pair<int, int> n2;
    n2.first = A.at(0);
    n2.second = 0;

    pair<int, int> n3;
    n3.first = A.at(0);
    n3.second = 0;
    

    for(int i = 1; i < A.size(); i++)
    {
        if(A.at(i) > n3.first)
        {
            swap(n1, n2);
            swap(n2, n3);
            n3.first = A.at(i);
            n3.second = i;
        }
        else if(A.at(i) > n2.first)
        {
            swap(n1, n2);
            n2.first = A.at(i);
            n2.second = i;
        }
        else if(A.at(i) > n1.first)
        {
            n1.first = A.at(i);
            n1.second = i;
        }
    }

    int sum = n1.first + n2.first + n3.first;

    if(n1.first == A.at(0) && n2.first == A.at(0))
    {
        return 0;
    }
    else
    {
        return sum;
    }
}
*/



