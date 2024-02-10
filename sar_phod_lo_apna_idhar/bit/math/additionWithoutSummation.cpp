#include <iostream>
using namespace std;

/*
ADDS TWO NUMBERS USING ONLY BINARY OPERATORS
*/

int addNumbers(int A, int B) {

    if(B == 0)
    return A;

    if(A== 0)
    return B;

    int a = A^B; //XOR covers addition without carry bit
    int b = (unsigned)(A&B) << 1; //Left Shift after AND sets the carry bits(unsigned) in the correct position

    return addNumbers(a, b);
}
