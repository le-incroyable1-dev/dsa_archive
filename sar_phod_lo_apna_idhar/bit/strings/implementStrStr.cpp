#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

#define ll long long
#define ld long double

//refer kmp.cpp for a more optimized solution

int strStr(const string A, const string B) {

    if(A.length() == 0 || B.length() == 0 || A.length() < B.length())
    return -1;

    int n = A.length();
    int m = B.length();

    int k = 0;
    int si = -1;

    for(int i = 0; i < n; i++){
        if(A.at(i) == B.at(k)){

            if(k == 0)
            si = i;

            if(i < n-1 && k < m-1 && A.at(i+1) != B.at(k+1)){
                k = 0;

                if(A.at(i) == B.at(0)){
                    if(k == 0)
                    si = i;

                    //cout << i << " " << k << " " << A.at(i) << endl;
                    k++;

                    if(k == m)
                    return si;
                }

                continue;
            }

            //cout << i << " " << k << " " << A.at(i) << endl;
            k++;

            if(k == m)
            return si;
        }
        else{
            k = 0;
            si = -1;

            if(A.at(i) == B.at(k)){
                if(k == 0)
                si = i;

                //cout << i << " " << k << " " << A.at(i) << endl;
                k++;

                if(k == m)
                return si;
            }
        }
    }


    return -1;
    
}


/*
aabaaaababaabbbabbabbbaabababaaaaaababaaabbabbabbabbaaaabbbbbbaabbabbbbbabababbaaabbaabbbababbb
bba

aaaaaabbaaaaaabaabbbaaababbaabaabbbbbbaabaabbabbabaababbabababbababaabbbabaababb
babbb
*/