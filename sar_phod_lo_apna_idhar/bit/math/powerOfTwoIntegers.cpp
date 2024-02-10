#include <iostream>
#include <cmath>
using namespace std;

int isPower(int n) {

    if(n==1)
    return 1;

    int A;
    float P;

    for(A =2; A <= sqrt(n); A++)
    {
        P = log10(n)/log10(A);
        if(ceil(P) == floor(P))
        {
            return 1;
        }
    }

    return 0;

}
