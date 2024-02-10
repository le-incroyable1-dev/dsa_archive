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
#define vpi vector< pii >c
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


//8 4 6 13 16 20 3 1 12


//correct
int nTriang(vector<int> &A) {
        int n=A.size();
        if(n<3)return 0;
        // now n>=3
        sort(A.begin(),A.end());
        int ans=0;

        for(int en=(n-1);en>=2;--en){
            // for this c, i need to find pairs(a,b) whose sum greater than c
            for(int be=0,mid=(en-1);be<mid;){
                if(A.at(be)+A.at(mid) > A.at(en)){
                    ans+=(mid-be)%(1000000007); //cout<<ans<<endl;
                    --mid; 
                }
                else{
                    ++be;
                }
            }
        }
        return (ans%(1000000007));
}

// int nTriang(vector<int> &A) {

//     sort(all(A));
//     ll n = A.size();

//     ll ans = 0;
//     int prev = INT_MIN;

//     rep(k, 2, n-1){
//         ll i = 0;
//         ll j = 1;
        
//         cout << k << endl;

//         if(k < n-1 && A[k+1] == A[k]){
//             cout << "skip" << endl;
//             continue;
//         }

//         bool found = false;

//         while(j < k && A[i] + A[j] <= A[k])
//         j++;

//         if(j < k){
//             found = true;
//             (ans += ((k-j)*(j+k-1))/2 - (k-j)*i)%=mod;
//             cout << ans << endl;
//         }

//         if(found == false){
//             j = k-1;

//             while(i < j && A[i] + A[j] <= A[k])
//             i++;

//             if(i < j){
//                 found = true;
//                 (ans += ((k-j)*(j+k-1))/2 - (k-j)*i)%=mod;
//                 cout << ans << endl;
//             }
//         }

//         prev = A[k];
//         ans %= mod;

//     }
    
//     cout << endl;

//     if(ans > INT_MAX)
//     return INT_MAX;
//     else
//     return (int)ans;    
// }


//O(n^2)
int nTriang2(vector<int> &A) {

    sort(A.begin(), A.end());

    long ans = 0;
    int n = A.size();
    int k;

    for(int i=0; i<n-2; i++){

        k = i+2;

        for(int j=i+1; j<n && A[i]!=0; j++){

            while(k<n && (A[i]+A[j] > A[k]))
                k++;

            ans += (k-j-1);
            ans %= 1000000007;
        }
    }

    return (int)ans;
}



/*
//INCOMPLETE
//TRY < O(n^2)
bool canFormTriangle(vi triplet){

    int a = triplet.at(0);
    int b = triplet.at(1);
    int c = triplet.at(2);

    if(a + b <= c)
    return false;

    if(b + c <= a)
    return false;

    if(a + c <= b)
    return false;

    return true;

}

vvi solveTriang(vi A, ll s){

    if(s == 3){

        vvi res;

        vi cur;
        cur.pb(A.at(A.size()-1));
        cur.pb(A.at(A.size()-2));
        cur.pb(A.at(A.size()-3));

        if(canFormTriangle(cur))
        res.pb(cur);

        return res;
    }


    vvi prevSet = solveTriang(A, s-1);

    ll n = prevSet.size();
    vvi newSet = prevSet;

    fr(i, n){
        int cur = A.at(A.size()-s);
        vi curTriplet = prevSet.at(i);

        vi triplet1 = curTriplet;
        vi triplet2 = curTriplet;
        vi triplet3 = curTriplet;

        triplet1.at(0) = cur;
        triplet2.at(1) = cur;
        triplet3.at(2) = cur;

        sort(all(triplet1));
        sort(all(triplet2));
        sort(all(triplet3));

        if(canFormTriangle(triplet1))
        newSet.pb(triplet1);

        if(canFormTriangle(triplet2))
        newSet.pb(triplet2);

        if(canFormTriangle(triplet3))
        newSet.pb(triplet3);
    }

    return newSet;

}

int nTriang(vector<int> &A) {

    ll n = A.size();

    sort(all(A));

    if(n < 3)
    return 0;

    if(n == 3){
        if(canFormTriangle(A))
        return 1;
        else
        return 0;
    }

    vvi triangs = solveTriang(A, n);

    

    set<vi> s;
    unsigned size = triangs.size();
    for( unsigned i = 0; i < size; ++i ) s.insert( triangs[i] );
    triangs.assign(s.begin(), s.end());

    return (int)triangs.size()%mod;
}

*/
void sol(){
    
}



int main(void){
    
    fast;

    vector<int> v = {1, 1, 1, 2, 2};
    cout << nTriang2(v) << endl;

    return 0;
}