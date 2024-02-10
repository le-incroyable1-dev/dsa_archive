#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int M = A.size();
    int N = A.at(0).size();

    if(M==0 || N==0)
    return;

    /*

    int d;

    if(M > N)
    d = M;
    else
    d = N;

    d++;

    */

    unordered_set<int> zr;
    unordered_set<int> zc;
    unordered_set<int>::iterator itr;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(A.at(i).at(j) == 0){
                zr.insert(i);
                zc.insert(j);
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            itr = zr.find(i);
            if(itr != zr.end())
            A.at(i).at(j) = 0;
            else{
                itr = zc.find(j);
                if(itr != zc.end()){
                    A.at(i).at(j) = 0;
                }
            }

        }
    }

    return;


}
