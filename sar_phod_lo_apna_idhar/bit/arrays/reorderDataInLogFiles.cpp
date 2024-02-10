#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

bool compare(string s1,string s2){
    
    string a = s1.substr(s1.find('-'));
    string b = s2.substr(s2.find('-'));
    
    return a == b ? s1 < s2 : a < b;
}

vector<string> reorderLogs(vector<string> &A) {

    vector<string> result;
    int count = 0;

    //auto log : A iterates over A and returns an element as "log"
    for(auto log : A){
        if(log.back() <= 'z' and log.back() >= 'a') {
            result.insert(result.begin(),log);
            count++;
        }

        else result.push_back(log);
    }

    //IMP
    sort(result.begin(),result.begin()+count,compare);
    //SIGMA MOVE, USE compare as next parameter to set a custom sorting condition

    return result;

}
