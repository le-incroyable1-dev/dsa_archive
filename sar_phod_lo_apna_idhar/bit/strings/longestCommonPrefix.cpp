#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPrefix(string_view prefix, string_view full)
{
    //using string_view ensures that whenever the prefix is larger than full it returns false itself
    return prefix == full.substr(0, prefix.size());
}

string helper(int si, int ei, vector<string> v){

    if(si == ei)
    return v.at(si);

    string pre = helper(si + 1, ei, v);

    if(pre == "")
    return pre;

    if(isPrefix(pre, v.at(si)))
    return pre;
    else{
        int l = pre.length() - 1;
        string subpre = pre.substr(0, l);

        while(l > 0 && !isPrefix(subpre, v.at(si))){
            l--;
            subpre = pre.substr(0, l);
        }

        if(l == 0)
        return "";
        else
        return subpre;
    }
}

string longestCommonPrefix(vector<string> &A) {
    
    if(A.size() == 0)
    return "";

    if(A.size() == 1)
    return A.at(0);

    return helper(0, A.size()-1, A);
} 
