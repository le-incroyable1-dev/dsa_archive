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
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define itr(type) type::iterator itr
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};


//greedy approach, which forms a square every time may not always work
//need to consider all cuts



void sol_dp(int a, int b){

    int dp[a][b];

    fr(i,a){
        fr(j, b){
            dp[i][j] = -1;

            double cl = i+1;
            double cw = j+1;

            if(cl == cw)
            dp[i][j] = 0;
            else if(cl == cw/(double)2.0)
            dp[i][j] = 1;
            else if(cw == cl/(double)2.0)
            dp[i][j] = 1;
            else if(cl == 1)
            dp[i][j] = cw-1;
            else if(cw == 1)
            dp[i][j] = cl-1;
        }
    }

    fr(i,a){
        fr(j, b){
            //dp[i][j] = INT_MAX;

            int cl = i+1;
            int cw = j+1;

            if(dp[i][j] == -1){

                dp[i][j] = 1+dp[cl-1][0]+dp[cl-1][cw-2];
                rep(nw, 1, cw-1){
                    dp[i][j] = min(dp[i][j], 1+dp[cl-1][nw-1]+dp[cl-1][cw-nw-1]);
                }
                
                rep(nl, 1, cl-1){
                    dp[i][j] = min(dp[i][j], 1+dp[nl-1][cw-1]+dp[cl-nl-1][cw-1]);
                }
                
            }
        }
    }

    cout << dp[a-1][b-1];
    return;
}

int sol(int w, int h){

    if(w == h){
        return 0;
    }
    else{
        if((double)w == (h*1.0)/(double)2 || (double)h == (w*1.0)/(double)2){
           return 1;
        }
        
        if(w == 1){
            return h-1;
        }
        
        if(h == 1){
            return w-1;
        }
    }

    int moves = INT_MAX;

    int mvsw;
    rep(nw, 1, w-1){
        mvsw = 1 + (sol(nw, h) + sol(w-nw, h));

        if(mvsw < moves)
        moves = mvsw;

        //cout << w << h << mvsw << endl;
    }

    int mvsh;
    rep(nh, 1, h-1){
        mvsh = 1 + (sol(w, nh) + sol(w, h-nh));

        if(mvsh < moves)
        moves = mvsh;

        //cout << w << h << mvsh << endl;
    }

    return moves;
}



int main(void){
    
    fast;

    int a, b;
    cin >> a >> b;
    //int res = INT_MAX;
    sol_dp(a, b);
    //cout << sol(a, b);
    //cout << res;
    return 0;
}