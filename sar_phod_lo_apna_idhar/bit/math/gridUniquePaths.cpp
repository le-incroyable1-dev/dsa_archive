#include <iostream>
using namespace std;


int uniquePaths(int A, int B) {

    if(A == 1 || B ==1) 
    return 1;

    //since the robo can only move down and right, once either it has reached
    //a row or a column of 1 we have a definite, unique path

    return uniquePaths(A-1,B) + uniquePaths(A,B-1);

    //tracing the possible paths backwards
}