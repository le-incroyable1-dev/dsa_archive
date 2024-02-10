#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
Can you find how many number of students we need if we fix that one student 
can read atmost V number of pages ?
*/

//EDITORIAL

class Solution {
    public:
        bool isPossible(vector<int> &V, int M, int curMin) {

            //student can read atmost curMin pages

            int studentsRequired = 1;
            int curSum = 0;

            for (int i = 0; i < V.size(); i++) {
                
                if (V[i] > curMin) return false;

                if (curSum + V[i] > curMin) {

                    studentsRequired++;
                    curSum = V[i]; 
                    if (studentsRequired > M) return false;

                } else {
                    curSum += V[i];
                }
            }

            return true;
        }

        int books(vector<int> Vec, int M) {

            long long sum = 0;
            int N = Vec.size();

            if(N < M)
                return -1;

            for(int i = 0; i < N; i++) {
                sum += Vec[i];
            }

            long long start = 0;
            long long end = sum, mid;

            int ans = INT_MAX; 

            while(start <= end) {
                mid = (start + end) / 2;
                if (isPossible(Vec, M, mid)) {
                    ans = min(ans, (int)mid);
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return ans;

        }
};