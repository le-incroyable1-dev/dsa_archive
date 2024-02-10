#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    vector<int> *path;
    
    if(root == NULL)
        return NULL;
    
    if(root -> right == NULL && root ->left == NULL)
    {
        path->push_back(root->data);
        return path;
    }
    
    vector<int> *p1;
    vector<int> *p2;
    vector<int> *maxp;
    
    if(root->right)
        p1 = longestPath(root->right);
    
    for(int i = 0; i < p1->size(); i++)
    {
        cout << p1->at(i); 
    } 
    
	if(root->left)
        p2 = longestPath(root->left);
    
    
     for(int i = 0; i < p2->size(); i++)
    {
        cout << p2->at(i); 
    } 
    
    if(p1->size() >= p2->size())
        maxp = p1;
    else
        maxp = p2;
    
    path->push_back(root->data);
    
    for(int i = 0; i < maxp->size(); i++)
    {
        path->push_back(maxp->at(i));    
    } 
     
    return path;
    
}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
