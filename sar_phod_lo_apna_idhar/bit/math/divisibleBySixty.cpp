#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int divisibleBy60(vector<int> &A) {

    if(A.size() == 0)
    return 0;

    if(A.size() == 1){
        if(A.at(0) == 0)
        return 1;
        else
        return 0;
    }

    bool zeroFound = false;

    vector<int> newA;

    for(long i = 0; i < A.size(); i++){
        
        if(A.at(i) == 0 && !zeroFound){
            zeroFound = true;
            continue;
        }

        newA.push_back(A.at(i));
    }

    if(!zeroFound)
    return 0;

    bool divbytwo = false;
    bool divbythree = false;

    int sumOfDigits = 0;


    for(long i = 0; i < newA.size(); i++){
        sumOfDigits += newA.at(i);

        if(newA.at(i) == 0 || newA.at(i) == 2 || newA.at(i) == 4 || newA.at(i) == 6 || newA.at(i) == 8)
        divbytwo = true;
    }
    

    if(sumOfDigits%3 == 0)
    divbythree = true;

    if(divbythree && divbytwo)
    return 1;
    else
    return 0;
}
