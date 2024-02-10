

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    Node* connect(Node* root) {

        Node* ans = root;
        while(root != NULL){
            Node *temp = new Node(0);
            Node *cur = temp;

            while(root != NULL){
                if(root->left != NULL){
                    cur->next = root->left; cur = cur->next;
                }

                if(root->right != NULL){
                    cur->next = root->right; cur = cur->next;
                }

                root = root->next;
            }

            root = temp->next;
        }

        return ans;
    }
};


int main(){

    Solution sol;
    Node *root = new Node(1);
    Node *l = new Node(2);
    Node *r = new Node(3);

    root->left = l;
    root->right = r;

    l->left = new Node(4);
    l->right = new Node(5);

    r->right = new Node(7);

    sol.connect(root);
    return 0;
}