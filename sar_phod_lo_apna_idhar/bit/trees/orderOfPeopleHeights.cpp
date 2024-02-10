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
#define tn TreeNode*
//#define itr(type) type::iterator itr
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

/*
Given this input:
Heights : 5 3 2 6 1 4
Infronts: 0 1 2 0 3 2

Sort both arrays using height:
Heights : 1 2 3 4 5 6
Infronts: 3 2 1 2 0 0

The output array should contain the heights and is arranged as follows:
there are 3 people in front of person with height 1 who are taller than 1. they have heights 5, 3 and 2.
there are 2 people in front of person with height 2 who are taller than 2. they have heights 5 and 3.
there are 1 people in front of person with height 3 who are taller than 3. they have height 5.
there are 2 people in front of person with height 4 who are taller than 4. they have heights 5 and 6.
there are 0 people in front of person with height 5 who are taller than 5.
there are 0 people in front of person with height 6 who are taller than 6.

So the output is:
5 3 2 1 6 4
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//O(n^2), recursive
void helper(int *ic, vpi &vec, ll index){

    ll n = vec.size();

    if(index == n)
    return;

    int req = vec.at(index).second;
    int val = vec.at(index).first;

    int ct = -1;


    fr(i, n){
        
        if(ic[i] == -1)
        ct++;
        
        if(ct == req){
            ic[i] = val;
            break;
        }
        else
        continue;

    }

    helper(ic, vec, index+1);
    return;
}

vector<int> order(vector<int> &A, vector<int> &B) {

    vpi vec;
    ll n = A.size();
    if(n <= 1)
    return A;

    fr(i, n)
    vec.pb(mp(A[i], B[i]));

    sort(all(vec));

    int *ic = new int[n];
    fr(i, n)
    ic[i] = -1;

    helper(ic, vec, 0);

    vi ans;
    fr(i, n)
    ans.pb(ic[i]);

    return ans;
}


//Efficient solution using segment tree
int empty_pos(vector<int> &tree, int pos) {
    int n = tree.size()/2, i = 0;
    while (i < n-1) {
        --tree[i];
        if (tree[2*i+1] > pos) i = 2*i+1;
        else {
            pos -= tree[2*i+1];
            i = 2*i+2;
        }
    }
    --tree[i];
    return i-(n-1);
}

vector<int> build_segment_tree(int len) {
    int n = pow(2, ceil(log2(len)));
    vector<int> tree(2*n);
    for (int i = 0; i <= len-1; ++i) tree[n-1+i] = 1;
    for (int i = n-2; i >= 0; --i) tree[i] = tree[2*i+1] + tree[2*i+2];
    return tree;
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << endl;
}

vector<int> order2(vector<int> &heights, vector<int> &infronts) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> perm(heights.size());
    for (int i = 0; i < perm.size(); ++i) perm[i] = i;
    sort(perm.begin(), perm.end(), [&](const int& a, const int& b) { return (heights[a] < heights[b]); });
    vector<int> tree = build_segment_tree(heights.size());
    vector<int> res(heights.size(), -1);
    for (int i = 0; i < perm.size(); ++i) res[empty_pos(tree, infronts[perm[i]])] = heights[perm[i]];
    return res;
}

