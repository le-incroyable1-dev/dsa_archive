#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define ll long long

#define ld long double

/*
A brute force solution to solve this problem is to do as instructed in the statement.
But this will give time out.
So can we reduce complexity?
Can we do Binary Search for each query?

*SIGMA MOVE*
Do you know product of divisors of a number can be written as N^D/2, where N is number and D is number of divisors of N.

We can solve this problem by doing the binary search for each query.
How?
First, you need to find that how many times an element will appear in array G. i.e in how many 
subarrays an element is the greatest one.
You can find that by finding the next greater element for the current element in both sides and 
then by multiplying them.
Once you found the frequency of each element in an array G, you can sort the 
pairs(product_of_divisors_of_element, frequency) according to there value in 
descending order followed by taking the prefix sum of there frequencies you 
can do the binary search for each query.

*/

//INCOMPLETE

vector<int> solve(vector<int> &A, vector<int> &B) {

    
    

}
