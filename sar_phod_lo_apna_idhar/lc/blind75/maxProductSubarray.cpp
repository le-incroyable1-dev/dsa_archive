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

class Solution {
public:


    ll helper(vector<int> &nums, ll n, ll si){
        
        if(si >= n-1)
        return nums[n-1];

        ll max = helper(nums, n, si+1);
        ll cval = nums[si];
        if(cval > max)
        max = cval;

        for(int i = si+1; i < n; ++i){
            cval *= nums[i];
            if(cval > max)
            max = cval;
        }

        return max;
    }

    //O(n^2)
    int maxProduct1(vector<int>& nums) {

        ll res = INT_MIN;

        res = helper(nums, nums.size(), 0);

        if(res < INT_MIN)
        return INT_MIN;
        else if(res > INT_MAX)
        return INT_MAX;
        else
        return res;
    }

    //O(n*log(n)) divide and conquer

    //testing
    int maxProduct4(vector<int> &nums){

        ll n = nums.size();

        if(n == 0)
        return 0;
        else if(n == 1)
        return nums[0];


    }

    //O(n) kadane's algorithm

    //testing, incorrect
    int maxProduct3(vector<int> &nums){

        ll n = nums.size();

        if(n == 0)
        return 0;
        else if(n == 1)
        return nums[0];

        ll ms = nums[0];
        ll cs = nums[0];

        rep(i, 1, n-1){

            if(nums[i] == 0){
                if(0 > ms)
                ms = 0;

                if(i == n-1)
                break;

                i++;
                cs = nums[i];

                if(cs > ms)
                ms = cs;

                continue;
            }
            else{
                cs = max(cs * (ll)nums[i], (ll)nums[i]);
                if(cs > ms)
                ms = cs;
            }
        }

        if(ms > INT_MAX)
        return INT_MAX;
        else return (int)ms;
        
    }

    //verified
    int maxProduct2(vector<int>&arr) {
        
        
        int mxp=INT_MIN,p=1,n=arr.size();
        
	    for(int i=0;i<n;i++)
	    {
	        p*=arr[i];
	        mxp=max(mxp,p);
	        if(p==0)
	        {
	            p=1;
	        }
	    }
        
	    p=1;
	    for(int i=n-1;i>=0;i--)
	    {
	        p*=arr[i];
	        mxp=max(mxp,p);
	        if(p==0)
	        {
	            p=1;
	        }
	    }
	    return mxp;
        
        
	}

    //random testing
    int maxProduct5(vector<int> &nums){
        ll n = nums.size();

        if(n == 0)
        return 0;
        else if(n == 1)
        return nums[0];

        ll nc = 0;
        ll cp = 1;

        fr(i, n){
            cp *= nums[i];
            if(nums[i] < 0)
            nc++;
        }

        if(nc == 0)
        return (int)cp;
        else if(nc == 1){
            
        }

    }
};

void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}