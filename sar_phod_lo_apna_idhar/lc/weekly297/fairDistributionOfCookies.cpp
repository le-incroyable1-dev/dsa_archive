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


//Brute force approach
//Also check bitmasking approach online
class Solution {
public:
    int ans=INT_MAX;
    
    void help(vector<int>& cook,int index,int n,vector<int>& stu,int k)
    {
        
        if(index==n)
        {
           
            ans=min(ans,*max_element(stu.begin(),stu.end()));
            
            return;
        }
        
        
        for(int i=0;i<k;i++)
        {
            //give index-cookie to ith child in the distribution
            
            stu[i]+=cook[index];
            

            help(cook,index+1,n,stu,k);
            
            stu[i]-=cook[index];
            
            
        }
    
        
    }
    
    
    int distributeCookies(vector<int>& cook, int k) {
        
        
        //distribution of cookies
        vector<int> stu(k);
        
        help(cook,0,cook.size(),stu,k);
        
        return ans;
      
        
    }
};

/*
//INCORRECT
class Solution {
public:

    ll calc(ll csum, ll t, vi cookies, ll ind, ll ct, ll mc){

        if(ind == cookies.size() || csum > t || ct == mc){
            return csum;
        }

        ll val1 = calc(csum+cookies.at(ind), t, cookies, ind+1, ct+1, mc);
        ll val2 = calc(csum, t, cookies, ind+1, ct, mc);

        if(val1 < t && val2 < t){
            ll ans = max(val1, val2);
            return ans;
        }
        else if(val1 < t)
        return val2;
        else if(val2 < t)
        return val1;
        else{
            ll ans = min(val1, val2);
            return ans;
        }

    }

    int distributeCookies(vector<int>& cookies, int k) {

        ll sum = 0;
        ll n = cookies.size();

        if(n == k)
        return *max_element(all(cookies));

        fr(i, n)
        sum += cookies.at(i);

        ll t = ceil((float)((float)sum/(float)k));

        ll ct = 0;

        ll mc = ceil((float)((float)n/(float)k));
        //max number of bags a child can receive so that each child can get atleast one bag

        ll ans = calc(0, t, cookies, 0, ct, mc);
        

        if(ans >= INT_MAX)
        return INT_MAX;
        else
        return (int)ans;
    }
};
*/