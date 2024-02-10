#include <iostream>
using namespace std;

int trailingZeroes(int A) {

    if(A<5)
    return 0;

    int ans = 0;
    int r = 1;

    while(pow(5,r) <= A)
    {
        ans += A/pow(5,r);
        r++;
    }

    return ans;
    
}