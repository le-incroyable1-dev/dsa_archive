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





//recursive solution, working correctly
void helper(int cur, int goal, int cmx, int &mx, unordered_set<int> path, unordered_map<int, vector<pair<int, int>>> &m){

    if(cur == goal){
        if(cmx > mx)
        mx = cmx;
        
        // cout << mx << " " << cmx << endl;
        // for(auto val : path)
        // cout << val << " ";
        
        // cout << endl << endl;
        // return;
    }

    vector<pair<int, int>> v = m.find(cur)->second;
    
    if(path.find(cur) == path.end())
    path.insert(cur);
    
    for(auto p : v){
        int nxt = p.first;
        int wt = p.second;

        if(path.find(nxt) == path.end()){
            int curmx = cmx;
            curmx = max(curmx, wt);
            unordered_set<int> p = path;
            p.insert(nxt);
            helper(nxt, goal, curmx, mx, p, m);
        }
    }

    return;
}

vector<int> solve(vector<vector<int> > &A, vector<vector<int> > &B) {

    ll n = A.size();
    ll q = B.size();
    vector<int> ans;

    unordered_map<int, vector<pair<int, int>>> m;
    unordered_map<int, vector<pair<int, int>>>::iterator itr;
    fr(i, n){
        itr = m.find(A[i][0]);
        if(itr == m.end()){
            vector<pair<int, int>> v;
            v.pb(mp(A[i][1], A[i][2]));
            m.insert(mp(A[i][0], v));
        }
        else
        itr->second.pb(mp(A[i][1], A[i][2]));

        itr = m.find(A[i][1]);
        if(itr == m.end()){
            vector<pair<int, int>> v;
            v.pb(mp(A[i][0], A[i][2]));
            m.insert(mp(A[i][1], v));
        }
        else
        itr->second.pb(mp(A[i][0], A[i][2]));
    }
    
    // for(auto val : m){
    //     cout << val.first << endl;
    //     for(auto v :val.second){
    //         cout << v.first << " " << v.second << endl;
    //     }

    //     cout << endl;
    // }

    fr(i, q){
        vector<int> cq = B[i];
        int mx;
        mx = INT_MIN;
        unordered_set<int> path;
        //path.insert(cq[0]);
        helper(cq[0], cq[1], INT_MIN, mx, path, m);
        ans.pb(mx);
    }

    return ans;

}