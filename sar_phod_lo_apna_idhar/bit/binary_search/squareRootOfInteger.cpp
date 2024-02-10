#include <iostream>
#include <vector>
using namespace std;


/*

*SIGMA MOVE*

Note: r * r will overflow if not done carefully. So instead, 
we eliminate the multiplcation and resort to a little bit of division.

Refer to the following solution:

*/


class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            int start = 1, end = x, ans;
            while (start <= end) {
                int mid = (start + end) / 2;

                /*
                Note how mid*mid <= x was avoided
                */
                if (mid <= x / mid) {
                    start = mid + 1;
                    ans = mid;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
};