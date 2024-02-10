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
#define vi vector< int >
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

class Solution {
public:
    

    //O(n) iterative
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right){
            int width = right - left;
            maxArea = max(maxArea, min(height[left], height[right])*width);

            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
	}

    //recursive test -- correct, faster

    void helper(vi &ht, ll si, ll ei, ll &mx){

        ll cur;

        if(ei-si == 1){
            cur = min(ht[si], ht[ei])*1;
            if(cur > mx)
            mx = cur;

            return;
        }

        cur = min(ht[si], ht[ei]) * (ei-si);
        if(cur > mx)
        mx = cur;

        if(ht[si] < ht[ei])
        helper(ht, si+1, ei, mx);
        else
        helper(ht, si, ei-1, mx);
    }

    int maxArea2(vector<int> &height){

        ll n = height.size();
        ll mx = 0;

        helper(height, 0, n-1, mx);

        if(mx > INT_MAX)
        return INT_MAX;
        else
        return (int)mx;
    }
};
