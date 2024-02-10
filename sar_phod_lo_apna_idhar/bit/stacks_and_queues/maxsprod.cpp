#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<int,int>
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


//Correct
int maxSpecialProduct(vector<int> &A) {

	ll ans = 0;

	ll n = A.size();
	vector<ll> rsv(n, 0);
	vector<ll> lsv(n, 0);

	stack<ll> s;

	per(i, n-1, 1){

		while(!s.empty() && A[s.top()] <= A[i])
		s.pop();

		s.push(i);

		if(!s.empty()){
			while(!s.empty() && A[s.top()] <= A[i-1])
			s.pop();

			if(!s.empty())
			rsv[i-1] = s.top();
		}

	}

	while(!s.empty())
	s.pop();

	rep(i, 0, n-2){

		while(!s.empty() && A[s.top()] <= A[i])
		s.pop();

		s.push(i);

		if(!s.empty()){
			while(!s.empty() && A[s.top()] <= A[i+1])
			s.pop();

			if(!s.empty())
			lsv[i+1] = s.top();
		}

	}

	while(!s.empty())
	s.pop();

	fr(i, n){
		if(lsv[i] != -1 && rsv[i] != -1){
			ll val = lsv[i]*rsv[i]*1LL;
            ans = max(ans, val);
		}
	}

	return (int)(ans%mod);
}







/*
To calculate LeftSpecialValue.

Lets make a stack A.
We will keep elements in strictly decreasing order in stack A.

When processing the ith element remove all the elements from 
the stack which have value less than or equal to ith element.
Now whatever element will remain at the top of index will give 
the index corresponding to LeftSpecialValue. If no element is at top then take it as 0.

Push ith element in stack A now.

You can see each element is pushed and popped for atmax one time. Hence the solution runs in O(n) time.

Do the similar thing for RightSpecialValue.
*/

//EDITORIAL
int maxSpecialProduct2(vector<int> &A) {
	int n = A.size();
	vector<int> LeftSpecialValue(n,0),RightSpecialValue(n,0);
	stack<int> leftCalc;
	leftCalc.push(0);
	LeftSpecialValue[0]=0;
	for(int i=1;i<n;i++){
		while(!leftCalc.empty()){
			if(A[leftCalc.top()]>A[i]) break;
			leftCalc.pop();
		}
		LeftSpecialValue[i] = (leftCalc.empty())?0:leftCalc.top();
		leftCalc.push(i);
	}

	stack<int> rightCalc;
	rightCalc.push(n-1);
	RightSpecialValue[n-1]=0;
	for(int i=n-2;i>=0;i--){
		while(!rightCalc.empty()){
			if(A[rightCalc.top()]>A[i]) break;
			rightCalc.pop();
		}
		RightSpecialValue[i] = (rightCalc.empty())?0:rightCalc.top();
		rightCalc.push(i);
	}


	long long mx = -1;
	for(int i=0;i<n;i++){
		mx=max(mx,LeftSpecialValue[i]*1LL*RightSpecialValue[i]);
	}
	return mx%1000000007;
}



void sol(){
    
}



int main(void){
    
    fast;

    test(t){
        sol();
    }
    
}