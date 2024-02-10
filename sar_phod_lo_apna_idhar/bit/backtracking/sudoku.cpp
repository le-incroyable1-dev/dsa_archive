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
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};



//EDITORIAL
class Solution {
    public:
        int rowhash[9][9], colhash[9][9], blockhash[3][3][9];

        bool solveSudoku(vector<vector<char> > &board, int position) {
            if (position >= 9*9) {
                return true;
            }
            int row = position / 9, col = position % 9;
            if (board[row][col] != '.') {
                return solveSudoku(board, position + 1);
            }
            for (int num = 0; num < 9; num++) {
                if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {
                    // Include num in the solution 
                    board[row][col] = '1' + num;
                    rowhash[row][num] = 1;
                    colhash[col][num] = 1;
                    blockhash[row / 3][col / 3][num] = 1;
                    if (solveSudoku(board, position + 1)) return true;
                    // Reset
                    board[row][col] = '.';
                    rowhash[row][num] = 0;
                    colhash[col][num] = 0;
                    blockhash[row / 3][col / 3][num] = 0;
                }
            }
            return false;
        }

        void solveSudoku(vector<vector<char> > &board) {
            memset(rowhash, 0, sizeof(rowhash));
            memset(colhash, 0, sizeof(colhash));
            memset(blockhash, 0, sizeof(blockhash));
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '1';
                        rowhash[i][num] = 1;
                        colhash[j][num] = 1;
                        blockhash[i / 3][j / 3][num] = 1;
                    }
                }
            }
            solveSudoku(board, 0);
        }
};
