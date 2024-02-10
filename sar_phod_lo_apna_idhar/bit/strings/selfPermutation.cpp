#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

int permuteStrings(string A, string B) {

    if(A.length() != B.length())
    return 0;

    unordered_set<char> myset;

    for(auto ch : A){
        myset.insert(ch);
    }

    unordered_set<char>::iterator itr;

    for(auto ch : B){
        itr  = myset.find(ch);
        if(itr == myset.end())
        return 0;
    }

    return 1;

}
