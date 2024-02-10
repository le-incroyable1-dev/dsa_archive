#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;


int repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //Note: if at any instance, you have three distinct elements from the array, 
    //if you remove them from the array, your answer does not change.

    int el1 = INT_MIN;
    int el1c = 0;
    int el2 = INT_MIN;
    int el2c = 0;

    for(int i = 0; i < A.size(); i++){
        if(el1 == INT_MIN && el2 != INT_MIN && el2 !=A.at(i)){
            el1 = A.at(i);
            el1c++;
        }
        else if(el1 == INT_MIN && el2 != INT_MIN && el2 ==A.at(i)){
            el2c++;
        }
        else if(el2 == INT_MIN && el1 != A.at(i)){
            el2 = A.at(i);
            el2c++;
        }
        else if(el2 == INT_MIN && el1 == A.at(i)){
            el1c++;
        }
        else{

            if(A.at(i) == el1){
                el1c++;
            }
            else if(A.at(i) == el2){
                el2c++;
            }
            else{
                el1c--;
                el2c--;

                if(el2c == 0 && el1c == 0){
                    el1 = INT_MIN;
                    el2 = INT_MIN;
                }
                else if(el2c == 0){
                    el2 = INT_MIN;
                }
                else if(el1c == 0){
                    el1 = INT_MIN;
                }
            }

        }
    }

    el1c = 0;
    el2c = 0;

    for(int i = 0; i < A.size(); i++){
        if(A.at(i) == el1){
            el1c++;
        }

        if(A.at(i) == el2){
            el2c++;
        }
    }

    //cout << el1 << " " << el1c << endl << el2 << " " << el2c << endl;

    if(el1c > A.size()/3)
    return el1;
    else if(el2c > A.size()/3)
    return el2;
    else
    return -1;

}