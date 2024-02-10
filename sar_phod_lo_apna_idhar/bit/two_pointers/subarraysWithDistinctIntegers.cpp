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
#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


/*
To directly count the subarrays with exactly B different integers is hard but to 
find the count of subarrays with at most B different integers is easy.

So the idea is to find the count of subarrays with at most B different integers, 
let it be C(B), and the count of subarrays with at most (B - 1) different integers, 
let it be C(B - 1) and finally take their difference, "C(B) – C(B – 1)" which is the required answer.

Count of subarrays with at most B different elements can be easily calculated through 
the sliding window technique.
*/


int at_most(vector<int> A,int k){

    int n = A.size(),s = 0,ans = 0,j = 0,i = 0;

    unordered_map<int,int> mp;

    while(j < n){
        
        mp[A[j]]++;
        
        while(mp.size() > k){
            mp[A[i]]--;
            if(mp[A[i]] == 0) mp.erase(A[i]);
            i++;
        }
        
        ans += (j-i+1);
        
        j++;
    }
    return ans;
}

int solve(vector<int> &A, int B) {
    return at_most(A,B)-at_most(A,B-1);
}



void sol(){
    
}



int main(void){
    
    fast;

    vector<int> A = {1,2,1,2,3};
    int b = 2;

    cout << solve(A, b);

    return 0;
}


//test

int solve2(vector<int> &v, int k){

    int l = 0;
    int r = 0;
    int n = v.size();

    int ans = 0;

    unordered_map<int, int> mp;

    while(r < n){
        mp[v[r]]++;

        if(mp.size() == k){

        }
    }

    return 0;
}


/*
void insertIn(unordered_map<int,int> &mymap, int el){
    unordered_map<int, int>::iterator itr;

    itr = mymap.find(el);

    if(itr == mymap.end()){
        mymap.insert(mp(el, 1));
    }
    else{
        itr->second = itr->second + 1;
    }
}

void popOut(unordered_map<int,int> &mymap, int el){
    unordered_map<int, int>::iterator itr;

    itr = mymap.find(el);

    if(itr == mymap.end()){
        return;
    }
    else{
        itr->second = itr->second - 1;

        if(itr->second == 0)
        mymap.erase(itr->first);
    }
}


int solve(vector<int> &A, int B) {

    ll n = A.size();

    ll l = 0;
    ll r = 0;

    unordered_map<int, int> mymap;
    //unordered_map<int, int>::iterator itr;
    int ans = 0;
    int b = B-1;
    //int repcount = 0;

    while(r < n && l < n){

        int csize = mymap.size();

        if(csize <= b){
            //int prevSize = csize;
            insertIn(mymap, A.at(r));

            if(mymap.size() <= b)
            ans += (r-l)+1;
            
            r++;
            continue;
        }
        else{
            popOut(mymap, A.at(l));

            if(mymap.size() <= b)
            ans += (r-l)+1;

            l++;
            continue;   
        }

    }

    return ans;
    
}
*/


/*
void insertIn(unordered_map<int,int> &mymap, int el){
    unordered_map<int, int>::iterator itr;

    itr = mymap.find(el);

    if(itr == mymap.end()){
        mymap.insert(mp(el, 1));
    }
    else{
        itr->second = itr->second + 1;
    }
}

void popOut(unordered_map<int,int> &mymap, int el){
    unordered_map<int, int>::iterator itr;

    itr = mymap.find(el);

    if(itr == mymap.end()){
        return;
    }
    else{
        itr->second = itr->second - 1;

        if(itr->second == 0)
        mymap.erase(itr->first);
    }
}


int solve(vector<int> &A, int B) {

    ll n = A.size();

    ll l = 0;
    ll r = 0;

    unordered_map<int, int> mymap;
    //unordered_map<int, int>::iterator itr;
    int ans = 0;
    int repcount = 0;

    while(r <= n && l < n){

        int csize = mymap.size();

        if(r == n){
            if(csize == B){
                ans++;
                popOut(mymap, A.at(l));
                l++;
                continue;
            }
            else if(csize > B){
                popOut(mymap, A.at(l));
                l++;
                continue;
            }
        }

        if(csize == B && r < n){
            ans++;
            insertIn(mymap, A.at(r));

            if(mymap.size() == csize){

            }
            r++;
            continue;
        }
        else if(csize < B && r < n){
            //int prevSize = csize;
            insertIn(mymap, A.at(r));
            r++;
            continue;
        }
        else{
            popOut(mymap, A.at(l));
            l++;
            continue;   
        }

    }

    return ans;
    
}


*/

