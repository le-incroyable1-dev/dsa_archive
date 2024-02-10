#include <bits/stdc++.h>
using namespace std;


string solution(int u, int l, vector<int> &c){
    int r1 = max(u, l);
    int r2 = min(u, l);

    string s1 = "";
    string s2 = "";

    for(auto x : c){
        if(x == 2){
            if(r1 == 0 || r2 == 0){ return "IMPOSSIBLE"; }
            s1 += "1"; s2 += "1";
            r1--;
            r2--;
        }
        else if(x == 1){
            if(r1 > 0){
                s1 += "1";
                s2 += "0";
                r1--;
            }
            else if(r2 > 0){
                s1 += "0";
                s2 += "1";
                r2--;
            }
            else{
                return "IMPOSSIBLE";
            }
        }
        else if(x == 0){
            s1 += "0";
            s2 += "0";
        }

        continue;
    }

    if(r1 > 0 || r2 > 0) return "IMPOSSIBLE";

    if(u > l) return s1 + "," + s2;
    else return s2 + "," + s1;
}


int main(){
    vector<int> c = {2,0,2,0};
    string res = solution(2,2,c);
    return 0;
}