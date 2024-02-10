#include <bits/stdc++.h>
using namespace std;


struct TrieNode{

public:

    TrieNode* l;
    TrieNode *r;

    bool end;

    TrieNode(){
        l = r = NULL; end = false;
    }


};

void insert(TrieNode *t, int num){
    TrieNode *root = t;
    for(int i = 0; i <= 31; ++i){
        if((1<<i) & num){
            if(root->r != NULL) root = root->r;
            else{
                root->r = new TrieNode();
                root = root->r;
            }
        }
        else{
            if(root->l != NULL) root = root->l;
            else{
                root->l = new TrieNode();
                root = root->l;
            }
        }
    }
}

int xor_val(TrieNode *t, int num){

    TrieNode *root = t;
    int val = 0;
    for(int i = 0; i <= 31; ++i){

        if(root == NULL) break;
        int x = num;
        if((x&(1<<i))){
            if(root->l != NULL) val += (1<<i), root = root->l;
            else root = root->r;
        }
        else{
            if(root->r != NULL) val += (1<<i), root = root->r;
            else root = root->l;
        }
    }

    return val;
}

int solve(vector<int> &a, vector<int> &b) {

    TrieNode *root = new TrieNode();
    int res = 0;
    for(auto x : a) insert(root, x);
    for(auto x : b) res = max(res, xor_val(root, x));

    return res;
}


int main(){
    vector<int> a = {1,2,3};
    vector<int> b = {4,1,2};

    solve(a, b);
    return 0;
}