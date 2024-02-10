#include <bits/stdc++.h>
using namespace std;

//for:-

//vertical and horizontal
int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

//diagonals
int dxdy1[4][2] = {{1,-1}, {-1, 1}, {1, 1}, {-1, -1}};

//all directions
int dxdy2[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}};

//checking validity of a point within matrix constraints
bool isValid(int i, int j, int n, int m){
    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}