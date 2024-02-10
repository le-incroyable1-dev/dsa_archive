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



//TLE 
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        ll n = nums1.size();

        ll ans = 0;
        int moves = k1+k2;
        
        vector<int> dif;
        fr(i, n){
            dif.pb(abs(nums1[i]-nums2[i]));
            //cout << dif[i] << endl;
        }
        
        priority_queue<int> pq;
        fr(i, n)
            pq.push(dif[i]);
        
        ll i = 0;
        
        while(moves > 0){
            //cout << moves << endl;
            
            //cout << pq.top() << endl;
            if(pq.top() == 0)
                break;
            
            int el = pq.top();
            pq.pop();
            pq.push(el-1);
            moves--;
            //cout << moves << endl;
        
        }
        
        // fr(i, n){
        //     //cout << dif[i] << endl;
        //     ll val = dif[i];
        //     ans += (val*val);
        // }
        
        while(!pq.empty()){
            ll val = pq.top();
            pq.pop();
            ans += (val*val);
        }
        
        return ans;
    }
        
};