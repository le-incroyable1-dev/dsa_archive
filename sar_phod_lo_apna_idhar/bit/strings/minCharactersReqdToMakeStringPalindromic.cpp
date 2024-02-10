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

string isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}

int solve(string s){

    int len = s.length();
    int ans = len-1;
    int index = len/2 - 1;
    
    if(isPalindrome(s) == "Yes")
    return 0;

    while(index >= 0){
        string fh = s.substr(0, index+1);
        string sh1 = s.substr(index+1);
        string sh2 = s.substr(index+2);
        reverse(all(fh));

        if(sh1.find(fh) == 0)
        ans = min(ans, (int)sh1.length() - (int)fh.length());
        else if(sh2.find(fh) == 0)
        ans = min(ans, (int)sh2.length() - (int)fh.length());
        
        index--;
    }

    return ans;
}



/*
Try to learn about LPS array used in KMP string matching algorithm. 
Modify your string and compute its LPS array to derive the answer

Each index of LPS array contains the longest prefix which is also a suffix. 
Now take the string and reverse of a string and combine them with a sentinal 
character in between them and compute the LPS array of this combined string. 
Now take the last value of the LPS array and subtract it with the length of the
original string, This will give us the minimum number of insertions required 
in the begining of the string .
*/


//TLE :(
// int solve(string A) {

//     int len = A.length();

//     if(len == 0 || len == 1)
//     return 0;

//     if(len == 2){
//         if(A.at(0) == A.at(1))
//         return 0;
//         else
//         return 1;
//     }

//     //bool found = false;
//     int ans = 0;

//     while(len > 0){

//         if(len == 1)
//         return ans;
        
//         if(len == 2){
//             if(A.at(0) == A.at(1))
//             return ans;
//             else{
//                 ans++;
//                 len--;
//                 continue;
//             }
//         }

//         /*

//         int si1 = 0;
//         int ei1 = len/2 - 1;

//         int ei2 = len-1;
//         int add;

//         if(len%2==0)
//         add=0;
//         else
//         add=1;

//         int si2 = ei1;
//         si2+=1;
//         si2 += add;

//         string s1 = A.substr(si1, ei1-si1+1);
//         string s2 = A.substr(si2, ei2-si2+1);

//         reverse(s1.begin(), s1.end());

//         if(s1 == s2)
//         return ans;
//         */

//        bool palindromic = true;

//        for (int i = 0; i < len / 2; i++) {
 
//             // If S[i] is not equal to
//             // the S[N-i-1]
//             if (A[i] != A[len - i - 1]) {
//                 ans++;
//                 len--;
//                 palindromic = false;
//                 break;
//             }
//         }

//         if(palindromic)
//         return ans;
//     }
// }
