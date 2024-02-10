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


void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool compare(Interval &i1, Interval &i2){
    if(i1.start < i2.start)
    return true;
    else if(i1.start == i2.start){
        if(i1.end < i2.end)
        return true;
        else 
        return false;
    }
    else
    return false;
}

bool compare(Interval &i1, Interval &i2){
    if(i1.start < i2.start)
    return true;
    else if(i1.start == i2.start){
        if(i1.end < i2.end)
        return true;
        else 
        return false;
    }
    else
    return false;
}

vector<Interval> merge(vector<Interval> &A) {

    ll n = A.size();
    if(n < 2)
    return A;

    sort(A.begin(), A.end(), compare);
    //fr(i, n)
    //cout << A[i].start << " " << A[i].end << endl;
    //cout << endl;
    vector<Interval> ans;
    

    rep(i, 0, n-2){

        Interval i1 = A[i];
        Interval i2 = A[i+1];

        Interval newInterval(INT_MAX, INT_MIN);

        if(i1.end < i2.start){
            //cout << i1.end << " " << i2.start << endl;
            ans.pb(i1);
            //ans.pb(i2);
            
            if(i == n-2)
            ans.pb(i2);
        }
        else{
            bool start = true;
            while(i1.end >= i2.start){
                //cout << i1.end << " " << i2.start << endl;
                newInterval.start = min(i1.start, i2.start);
                newInterval.end  = max(i1.end, i2.end);
                //cout << newInterval.start << " " << newInterval.end << endl;
                //i1 = newInterval;
                
                if(start){
                    i += 2;
                    start = false;
                }
                else
                ++i;

                if(i > n-1)
                break;

                i1 = newInterval;
                i2 = A[i];
            }
            
            ans.pb(newInterval);
            
            if(i == n-1)
            ans.pb(i2);
            
            i--;
        }
    }

    return ans;
}