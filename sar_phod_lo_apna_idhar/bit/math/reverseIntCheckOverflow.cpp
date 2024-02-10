#include <iostream>
using namespace std;

int reverse(int A) {
    int sign=1, rem, B=0;
    
    if(A<0) sign=-1;

    A = A * sign;

    while(A>0){
        rem = A%10;

        if(B >INT_MAX/10 - rem) 
        return 0;

        B = B*10 + rem;
        A/=10;
    }

    return B*sign;
}

/*
if(B >INT_MAX/10 - rem) 
        return 0;

if at in the prev iteration B became greater than INT_MAX overflow has occured 

i.e. INT_MAX < B*10 + REM
or, B > INT_MAX/10 - REM

*/
