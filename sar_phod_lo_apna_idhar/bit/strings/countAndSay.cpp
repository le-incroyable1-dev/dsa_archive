#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string countAndSay(int A) {

    if(A == 1)
    return "1";

    string prev = countAndSay(A-1);
    string res = "";

    int plen = prev.length();

    int count = 1;
    char num;

    for(int i = 0; i < plen; i++){

        num = prev.at(i);
        count = 1;

        if(i < plen - 1){
            int k = i;

            while(k < plen - 1 && prev.at(k+1) == prev.at(k)){
                k++;
                count++;
            }

            i = k;

        }

        res.append(to_string(count));
        res.append(string(1, num));
    }

    return res;

}
