#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
The LL makes the integer literal of type long long.

So 2LL, is a 2 of type long long.

Without the LL, the literal would only be of type int.

This matters when you're doing stuff like this:

1   << 40
1LL << 40
With just the literal 1, (assuming int to be 32-bits, you shift beyond the size 
of the integer type -> undefined behavior). With 1LL, you set the type to long 
long before hand and now it will properly return 2^40.
*/

/*
Suppose the given array contains only binary numbers, i.e A[i] belongs to [0, 1].

Let X be the number of elements equal to 0, and Y be the number of elements equals to 1.

Then, sum of hamming distance of all pair of elements equals 2XY, as every pair containing one element from X 
and one element from Y contribute 1 to the sum.

As A[i] belongs to [0, 2^31 - 1] and we are counting number of different bits in each pair, we can consider 
all the 31 bit positions independent.

For example:
A = [2, 4, 6] = [010, 100, 110]

At bit position 0 (LSB): x = 3, y = 0
At bit position 1: x = 1, y = 2
At bit position 2(MSB): x = 1, y = 2

Total sum = number of pairs having different bit at each bit-position = (2 * 3 * 0) + (2 * 1 * 2) + (2 * 1 * 2) = 8

Time complexity: O(N)
Space complexity: O(1)
*/

int hammingDistance(const vector<int> &A) {
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
        int cntBitOne = 0, cntBitZero = 0;
        for(int i = 0; i < inputSize; i++) {
            if (A[i] & (1 << bitPosition)) cntBitOne++;
            else cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod) sum = sum - mod;
    }
    return sum;
}



/*
int helper(int a, int b)
{
    int c = a^b; //xor

    int res = 0;

    while (c > 0) {
 
        if(c%2 == 1)
        res++;


        c = c / 2;
    }

    return res;
    
}

int hammingDistance(const vector<int> &A) {

    if(A.size() < 2)
    return 0;

    int dist =0;

    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            if(j!=i)
            {
                dist += helper(A.at(i), A.at(j));
            }
        }
    }

    return dist%1000000007;
}

*/