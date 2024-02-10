#include <bits/stdc++.h>
using namespace std;


int sp;
int so;
bool compare(vector<string> &v1, vector<string> &v2){
    if(so == 0){
        return stoi(v1[sp]) < stoi(v2[sp]);
    }
    else{
        return stoi(v1[sp]) > stoi(v2[sp]);
    }
}

vector<string> solve(vector<vector<string>> items, int sortParameter, int sortOrder, int ip, int pn){

    vector<string> ans;
    sp = sortParameter;
    so = sortOrder;
    int n = items.size();
    sort(items.begin(), items.end(), compare);

    for(int i = ip*pn; i < min(n, (ip+1)*pn); ++i){
        ans.push_back(items[i][0]);
    }

    return ans;

}

int main(void){

    vector<vector<string>> items = {{"item1", "10", "15"}, {"item2", "3", "4"}, {"item3","17", "8" }};

    for(auto val : solve(items, 1, 0, 2, 1))
    cout << val << " ";

    return 0;

}