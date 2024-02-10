#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    unordered_map<int, int> ntd;
    unordered_map<int, int> nth;

    int helper(TreeNode* node, int level){

        if(node == NULL)
        return 0;

        int lh = 0;
        int rh = 0;

        ntd[node->val] = level;
        lh = helper(node->left, level+1);
        rh = helper(node->right, level+1);

        int ht = max(lh, rh);
        nth[node->val] = ht;

        return ht;

    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        vector<int> ans;
        int tht = helper(root, 0);

        int q = queries.size();

        for(int i = 0; i < q; ++i){
            int cq = queries[i];
            
        }
        
    }
};