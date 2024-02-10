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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> g(m,vector<char>(n,'0'));
        
        //fill the position of guards.
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0],y=guards[i][1];
            g[x][y]='g';
        }
        
        //fill the position of walls
        for(int i=0;i<walls.size();i++){
            int x=walls[i][0],y=walls[i][1];
            g[x][y]='w';
        }
        
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0],y=guards[i][1];
            
            //check for guards or walls in upper direction.
            for(int j=x-1;j>=0;j--){
                if(g[j][y]=='g' or g[j][y]=='w'){
                    break;
                }
                g[j][y] = '1'; //fill the cell as guarded
            }
            
            //check for guards or walls in right direction.
            for(int j=y+1;j<n;j++){
                if(g[x][j]=='g' or g[x][j]=='w'){
                    break;
                }
                g[x][j] = '1';
            }
            
            //check for guards or walls in downward direction.
            for(int j=x+1;j<m;j++){
                if(g[j][y]=='g' or g[j][y]=='w'){
                    break;
                }
                g[j][y] = '1';
            }
            
            //check for guards or walls in left direction.
            for(int j=y-1;j>=0;j--){
                if(g[x][j]=='g' or g[x][j]=='w'){
                    break;
                }
                g[x][j] = '1';
            }
        }
        
        int res=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if g[i][j] is '0' it means the cell is not guarded.
                if(g[i][j]=='0'){
                    res++;
                }
            }
        }
        return res;
    }
};
