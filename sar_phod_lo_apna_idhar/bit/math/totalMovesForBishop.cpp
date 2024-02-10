#include <iostream>
using namespace std;

int solve(int A, int B) {

    int totalMoves = 0;

    int r1 = A;
    int c1 = B;

    while(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
    {
        c1++;
        r1--;

        if(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
        {
            totalMoves++;
        }
    }

    r1 = A;
    c1 = B;

    while(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
    {
        c1++;
        r1++;

        if(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
        {
            totalMoves++;
        }
    }

    r1 = A;
    c1 = B;

    while(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
    {
        c1--;
        r1++;

        if(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
        {
            totalMoves++;
        }
    }

    r1 = A;
    c1 = B;

    while(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
    {
        c1--;
        r1--;

        if(r1 <= 8 && c1 <= 8 && r1 >= 1 && c1 >= 1)
        {
            totalMoves++;
        }
    }

    return totalMoves;

}