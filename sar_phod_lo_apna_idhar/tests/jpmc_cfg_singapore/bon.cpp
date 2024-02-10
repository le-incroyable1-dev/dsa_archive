#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<string> e, vector<int> v){
    vector<int> ans;

    int n = e.size();

    for(int i = 0; i < n; ++i){

        //int cur_ans = 0;
        string cur = e[i];
        int r = v[i];

        int lc = 0;
        int rc = 0;

        int j = 0;
        bool done = false;

        if(cur[cur.size()-1] == '<'){
            ans.push_back(0);
            continue;
        }

        while(j < cur.length()){
            if(cur[j] == '>')
            lc++;
            else if(cur[j] == '<')
            rc++;

            // if(lc && !rc){
            //     ans.push_back(0);
            //     done = true;
            //     break;
            // }

            j++;
            
        }
        
        if(done)
        continue;

        int req = lc-rc;
        if(req >= 0 && req <= r)
        ans.push_back(1);
        else
        ans.push_back(0);

        continue;
    }

    return ans;
}

int main(){
    vector<string> e = {"<<>>", "<>", "<><>", ">>", "<<>", "><><"};
    vector<int> v = {0,1,2,2,2,2};

    for(auto b : solve(e, v))
    cout << b << " ";
    return 0;
}