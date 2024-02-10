#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
We will represent the number B as the sum of factorials, or more specifically 
express the number in factorial number system.

Here, everything is 0 - indexed including B, so we will subtract 1 from B from the beginning.
Let us first construct the factorial representation of A = 3, B = 3:

B = B - 1 = 2
B = 2 = 1 * 2! + 0 * 1! + 0 * 0! = (1, 0, 0)

This means, we first take the element at 1st index, then 0th index, then again 0th index.
So, our permutation would look like ->

List    |    Perm
--------|-----------
1, 2, 3 |  -, -, -
1, 3    |  2, -, -
3       |  2, 1, -
-       |  2, 1, 3

We can see that [2, 1, 3] is the 3rd lexicographically sorted permutation of length 3.

Since, k <= 1e18, we only need to calculate upto 20!.
We can just simply put 1, 2,... before the last 20 numbers.

*/


/*
//TLE DE RHA BC

int fact(int n)
{
        if(n==0) return 1 ; else return (n*fact(n-1));
}

void swap(int &n, int &m)
{
    int temp = m;
    m = n;
    n = temp;
}

vector<int> findPerm(int A, long B) {

    vector<int> res;

    for(int i = 0; i < A; i++){
        res.push_back(i+1);
    }

    if(B==1)
    return res;

    int pos = 0;

    while(fact(pos) <= B)
    pos++;

    pos--;


    reverse(res.end()-pos, res.end());

    int rem = B - fact(pos);


    while(rem){

        int smol = A-1;

        for(int i = A-2; i >= 0; i--){

            if(res.at(i) < res.at(i+1)){

                while(res.at(smol) < res.at(i)){
                    smol--;
                }

                swap(res.at(i), res.at(smol));
                reverse(res.end()-(A-i-1), res.end());
                break;
            }

            if(res.at(smol) > res.at(i)){
                smol = i;
            }
        }

        rem--;
    }


    return res;


}

*/
