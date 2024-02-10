#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(vector<int> &A, int B) {

    int N = A.size();

    if(N==1){
        return A.at(0)-B;
    }

    vector<int> htcuts;
    sort(A.begin(), A.end());

    htcuts.push_back(A.at(N-1)-A.at(N-2));
    int k = 0;
    int prevDif = htcuts.at(0);

    if(prevDif >= B){
        return A.at(N-1)-B;
    }

    int bi = -1;

    for(int i = N-3; i >= 0; i--){

        int cdif = A.at(i+1)-A.at(i);
        int val = prevDif + (k+2)*cdif;

        if(val == B)
        return A.at(i);

        bi = i;
        
        if(val > B)
        break;

        htcuts.push_back(val);
        k++;
        prevDif = htcuts.at(k);

    }

    //cout << htcuts.at(k) << endl;

    int curht = htcuts.at(k);

    int dif = (ceil)(((float)B-(float)curht)/(float)(k+2));

    bi++;
    //cout << curht << endl << dif << endl << bi << endl;

    return A.at(bi)-dif;

}

