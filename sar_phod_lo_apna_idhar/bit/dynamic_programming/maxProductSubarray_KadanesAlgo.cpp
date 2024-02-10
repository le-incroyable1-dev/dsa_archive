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
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


/*
Let us imagine a scenario.

Let the array for which we need to find the maximum product be nums.

nums = [1] 
What is the maximum product ? 1. Right ?

Now, what is the maximum product of nums = [1, -3]?

Answer is 1.

Let us extend this further. Now the array, nums = [1, -3 -5]?

15 now.

Let us have nums = [1, -3, -5, -2, 0, 4, 9, 0, 3, -8, 7, -6].

Now the answer is 1008. How do we arrive at this ?

We know if we multiply two numbers, the product will be big if the numbers are both big in magnitude and are of same sign.

Two large negative numbers produce a large positive product
Two large positive numbers produce a large positive product
A large positive and a large negative number produce a large negative product (which may or may not be used further with another negative number to produce a large positive product)
Thus, to find the maximum product in a subarray, we have to keep track of both local minimum product as well as local maximum product.

The greatest of all local maximum products will be our answer.

Mathematically,

localMax=max(previousLocalMax∗currentNumber,currentNumber),ifcurrentNumber>=0 

localMax=max(previousLocalMin∗currentNumber,currentNumber),ifcurrentNumber<0 

localMin=min(previousLocalMin∗currentNumber,currentNumber),ifcurrentNumber>=0 

localMin=max(previousLocalMax∗currentNumber,currentNumber),ifcurrentNumber<0 

answer=max∀x(localMax) 

Programmatically,

int maxProduct(vector<int>& nums) { 
	int localMax = nums[0]; 
	int localMin = nums[0]; 
	int maxProd = nums[0]; 
	for(int i = 1; i < nums.size(); i ++){ 
		if(nums[i] > 0){ 
			localMax = max(localMax * nums[i], nums[i]); 
			localMin = min(localMin * nums[i], nums[i]); 
		} else{ 
			int localMaxNeg = max(localMin * nums[i], nums[i]); 
			localMin = min(localMax * nums[i], nums[i]); 
			localMax = localMaxNeg; 
		} 
		maxProd = max(maxProd, localMax); 
	} 
	return maxProd; 
} 

*/
int maxProduct(const vector<int> &A) {
    //int p = 1;
    
    int n = A.size();
    if(n == 0)
    return 0;
    
    int maxp = A[0];
    int localMax = A[0];
    int localMin = A[0];
    
    for(int i = 1; i < n; i++){
        if(A[i] > 0){
            localMax = max(A[i], localMax * A[i]); 
            localMin = min(localMin * A[i], A[i]);
        }
        else{
            
            int localMaxNeg = min(A[i], localMax * A[i]);
            localMax = max(localMin * A[i], A[i]);
            localMin = localMaxNeg;
        }
        
        cout << i << " " << localMin << " " << localMax << endl;
        
        maxp = max(maxp, localMax);
    }
    
    return maxp;
}
