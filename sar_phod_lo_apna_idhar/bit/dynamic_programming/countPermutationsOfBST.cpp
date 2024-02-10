// // BST follows the property that all values in left subtree and less than value at current node and all values in right subtree are greater than current node.
// // If we fix the root node, the BST formed will be unique.

// // Also, the actual values that are being inserted in BST don’t matter. So, we can directly deal with number of values being inserted in BST instead of the actual values. This helps in defining states of DP.

// // Now, what should be the states of DP? Of course, number of elements is one state. Other can be the height required.

// // So, we define DP(N, M) as the number of permutations of N elements which when inserted into BSTs generate BSTs of height exactly M.

// // Now, to define a recurrence, we’ll iterate over the root of BST we choose. We have N options and based on each option, the size of left and right subtrees are defined.

// // If i’th element is choosen as root, the left subtree will now contain (i - 1) elements and right subtree will contain (N - i) elements.
// // Now, at least one of these subtrees must have a height of (M - 1) because we are right now solving for height M.
// // Again, we’ll iterate over the heights of left and right subtrees.

// // Now, number of permutations to form left subtree of size x with some height are say, X. Also, we call these permutations set A.
// // And similarly, number of permutations to form right subtree of size y with some height are say, Y. And we call these permutations set B.
// // Now, we can choose any permutation from A and any permutation from B, to form a unique tree. So, there are total of X*Y permutations. Also, any sequence of size (x+y) can give the same BST if the mutual ordering of the permutation from set A and permutation of set B is maintained. There are choose(x + y, y) ways to do that. So, total ways are X*Y*choose(x + y, y).

// // So, in terms of pseudo code:

// def rec(N, M):
//     if N<=1:
//         if M==0: return 1
//         return 0;

//     ret=0

//     for i=1 to N:
//         x = i-1
//         y = N-i

//         ret1=0

//         //iterate over height of left subtree
//         for j = 0 to M-2:
//             ret1 = ret1 + rec(x, j)*rec(y, M-1)

//         //iterate over height of right subtree
//         for j = 0 to M-2:
//             ret1 = ret1 + rec(y, j)*rec(x, M-1)

//         //add the case when both heights=M-1
//         ret1 = ret1 + rec(x, M-1)*rec(y, M-1)

//         //rather than considering all possible permutations of 1...A, we take all combinations of y and x from a size of x+y
//         //as we are only considered with the NUMBER of permutations
//         ret = ret + ret1*choose(x+y, y)

//     return ret
// We can precalculate choose table in O(N*N).
// Also, take care of modulo arithmetic.


#include <bits/stdc++.h>
using namespace std;


int cntPermBST(int A, int B) {
    if(A<=B) return 0;
    int N = (int) (1e9 + 7);
    vector<vector<long long>> dp(A+1, vector<long long> (B+2, 0));
    vector<vector<long long>> C(A+1, vector<long long> (A+1, 0));
   
     for(int n = 0; n <= A; n ++) {
            C[n][0] = 1;
            C[n][n] = 1;
        }
        for(int n = 1; n <= A; n ++) {
            for(int r = 1; r < n; r ++) {
                C[n][r] = (C[n - 1][r - 1] + C[n - 1][r])%N;
                //nCr = n-1Cr-1 + n-1Cr
            }
        }
   
    dp[1][0] = 1;
    for(int i = 0;i<=B;i++) dp[0][i] = 1;
   
    for(int i = 1;i<=A;i++)
    {
        for(int j = 1;j<=B;j++)
        {
           long long temp = dp[i][j-1];
           if(j<=i-1){
           for(int k = 0;k<i;k++)
           {
               if(i-1-k>=0) temp=((temp%N) + (((dp[k][j-1])%N*(dp[i-1-k][j-1])%N)%N*C[i-1][k])%N)%N;
           }
           if(j>=2) temp=((temp%N) - (dp[i][j-1]%N))%N;
           }
           dp[i][j] = temp;
        }
    }
    int k = ((dp[A][B]%N)-(dp[A][B-1]%N))%N;
    if(k<0) k+=N;
    return k;
}