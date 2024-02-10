#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1) { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }

/*
21 35 48 33 26 16 11 14 37 41 12 47 38 23 4 0 10 47 30 46 38 26
21 51 53 40 54 23 39 33 70 61 45 78 77 50 12 4 25 77 35 53 38 61
1
*/