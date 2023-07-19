
#include <bits/stdc++.h>

using namespace std;

struct Node {
    public:
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};

void preorder(Node * root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node * root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

void postorder(Node * root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<endl;
}



int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}