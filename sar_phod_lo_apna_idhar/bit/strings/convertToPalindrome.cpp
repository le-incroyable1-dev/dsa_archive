#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

#define ll long long
#define ld long double

int solve(string a) {
    int j = a.length() - 1;
    int i = 0;
    int flg = 0;
    
    while(i<j){
        
        if(a.at(i) != a.at(j)) {
            if(flg == 0){
                if(a.at(i) == a.at(j-1)) {
                    j--;
                } else if (a.at(i+1) == a.at(j)) {
                    i++;
                }
                flg = 1;
                continue;
            } else{
                break;
            }
        }
        i++;j--;
    }
    if(i<j)
        return 0;
    return 1;
}
