#include <bits/stdc++.h>
using namespace std;


vector<char> res;

void bfs(vector<vector<int>> &g, int s){

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int sz = q.size();

        while(sz--){
            int cur = q.front(); q.pop();
            res.push_back(char('a' + cur));

            for(auto u : g[cur]) q.push(u);
        }

        continue;
    }

    return;

}

vector<char> getAlienLanguage(string* dictionary, int s){
    // Write your code here.

    int init = s-1;
    int n = dictionary->size();
    vector<vector<int>> g(26);

    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < min(dictionary[i].length(), dictionary[i+1].length()) ; ++j){
            if(dictionary[i][j] != dictionary[i+1][j])
            g[dictionary[i][j] - 'a'].push_back(dictionary[i+1][j] - 'a');
        }
    }


    //cout << "hello\n";

    bfs(g, init);

    return res;
}

int main(){

    int n = 3;
    string *dict = new string[n];
    dict[0] = "caa";
    dict[1] = "aaa";
    dict[2] = "aab";

    vector<char> ans = getAlienLanguage(dict, 3);

    return 0;
}