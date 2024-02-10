#include <bits/stdc++.h>
using namespace std;


vector<string> func(vector<string> &s){

    int n = s.size();
    vector<string> ans;
    unordered_map<string, int> m;
    for(int i = 0; i < n; ++i){
        string cur = s[i];
        sort(cur.begin(), cur.end());

        if(m.find(cur) != m.end()) continue;
        else m[cur] = i, ans.push_back(s[i]);
    }

    //for(auto str : s) cout << str << " ";
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    vector<string> s = {"code", "aaagmnrs", "anagrams", "doce"};
    for(auto str : func(s)){
        cout << str << " ";
    }

    cout << "\n";
    return 0;

}