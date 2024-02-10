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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

//Sliding Window
//O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
          
        int i=0;
        long long int one=0;
        long long sum=0;
        long long int count=0;
        
        int n=nums.size();
        
        for(int j=0;j<n;j++)
        {
                sum+=nums[j];
                one=sum*(j-i+1);
        
                while(one>=k)
                {
                    
                    sum=sum-nums[i];
                    
                    i++;
                    
                    one=sum*(j-i+1);

                }
                
                count+=j-i+1;    
            
        }
        
        
        return count;
        
    }
};








/*
Sliding Window Concept
For those who are confused, let's use the example nums = [10,5,2,6]:

If we start at the 0th index, [10,5,2,6], the number of intervals is obviously 1.
If we move to the 1st index, the window is now [10,5,2,6]. The new intervals created are [5] and [10,5], so we add 2.
Now, expand the window to the 2nd index: [10,5,2,6]. The new intervals are [2], [5,2], and [10,5,2], so we add 3.
The pattern should be obvious by now; we add right - left + 1 to the output variable every loop!

Similar
https://leetcode.com/problems/subarray-product-less-than-k/solution/
*/