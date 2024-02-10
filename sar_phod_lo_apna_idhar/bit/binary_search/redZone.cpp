#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long

/*
Notice that the answer is monotonic. If there is a red zone on day d, 
then there will be a red zone for all days x >= d.

So, we can binary search.

How do we check if there is a red zone on day d.

If we draw a circle of radius d with the orange zone coordinate as center, 
we need to check if a point is within at least B circles.

Notice that if an area has a maximum number of circles in it, then it will 
have at least one point which is an intersection point of 2 circles.

So, we can find all the intersection points of every pair of circles and 
find the point which is in maximum number of circles.
*/


//INCOMPLETE

int daysToOrange(int x1, int y1, int x2, int y2){
    ll dist = pow((ll)(x2-x1), 2) + pow((ll)(y2-y1), 2);
    return ceil((int)sqrt(dist));
}


int solve(vector<vector<int>> &A, int B) {

    if(A.size() == 2)
    return daysToOrange(A.at(0).at(0), A.at(0).at(1), A.at(1).at(0), A.at(1).at(1));

    unordered_map<int, int> pointToDays;


}
