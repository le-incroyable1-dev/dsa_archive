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

// O(n^3) solution
// Notice that the answer is monotonic. If there is a red zone on day d, then 
// there will be a red zone for all days x >= d.

// So, we can binary search.

// How do we check if there is a red zone on day d.

// If we draw a circle of radius d with the orange zone coordinate as center, 
// we need to check if a point is within at least B circles.

// Notice that if an area has a maximum number of circles in it, then it will 
// have at least one point which is an intersection point of 2 circles.

// So, we can find all the intersection points of every pair of circles and find 
// the point which is in maximum number of circles.

long double dist(pair<long double,long double>a, pair<long double,long double>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool check(vector<pair<long double,long double>>A, int B,long double d){
    d*=d;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
           // pair<long double,long double> A[i] = A[i], A[j] = A[j];
            long double h = dist(A[i],A[j]);
            long double D = (4*d-h)/h;
            if(4*d-h>=0.0){
                int cn1=0,cn2=0;
                pair<long double,long double>x,y;
                x.first = ((A[i].first+A[j].first)+sqrt(D)*(A[i].second-A[j].second))/2;
                x.second = ((A[i].second+A[j].second)+sqrt(D)*(A[j].first-A[i].first))/2;
                y.first = ((A[i].first+A[j].first)-sqrt(D)*(A[i].second-A[j].second))/2;
                y.second = ((A[i].second+A[j].second)-sqrt(D)*(A[j].first-A[i].first))/2;
                for(int k=0;k<A.size();k++){
                    if(dist(x,A[k])<=d+0.1)cn1++;
                    if(dist(y,A[k])<=d+0.1)cn2++;
                }
                if(cn1>=B){
                    return true;
                }
                if(cn2>=B){
                    return true;
                }
            }
        }
    }
    return false;
}
int solve(vector<vector<int> > &A, int B) {
    vector<pair<long double,long double>>C;
    int r = 0, l=0;
    for(int i=0;i<A.size();i++){
        long double xcoor=A[i][0]*(1.0);
        long double ycoor=A[i][1]*(1.0);
        r=max({r,A[i][0],A[i][1]});
        C.push_back({xcoor,ycoor});
    }
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(C,B,mid))
            r = mid-1;
        else l = mid+1;
    }
    return l;
}