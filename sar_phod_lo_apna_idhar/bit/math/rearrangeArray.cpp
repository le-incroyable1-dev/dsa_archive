#include <iostream>
#include <vector>
using namespace std;

/*

SIGMA MOVE!

If you had extra space to do it, the problem will be very easy.
Store a copy of Arr in B.

And then for every element, do Arr[i] = B[B[i]]

Lets restate what we just said for extra space :

"If we could somehow store 2 numbers in every index" ( that is, Arr[i] can contain
the old value and the new value somehow ), then the problem becomes very easy.
NewValue of Arr[i] = OldValue of Arr[OldValue of Arr[i]]

Now, we will do a slight trick to encode 2 numbers in one index.
This trick assumes that N * N does not overflow.

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.
Given a number as

   A = B + C * N   if ( B, C < N )
   A % N = B
   A / N = C
We use this fact to encode 2 numbers into each element of Arr.

*/


void swap(int &n, int &m)
{
    int temp = m;
    m = n;
    n = temp;
}

void arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();

    if(n<2)
    return;

    for(int i = 0; i < A.size(); i++){
            A.at(i) += (A.at(A.at(i))%n)*n;
            //two numbers in one OP
    }

    for(int i = 0; i < A.size(); i++){
            A.at(i) /= n;
    }

}

