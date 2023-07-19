#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isSym(TreeNode * l,TreeNode * r){
    if(l == nullptr && r == nullptr) return true;
    if(l == nullptr) return false;
    if(r == nullptr) return false;

    if(l->val != r->val) return false;
    return isSym(l->left,r->left) && isSym(l->right,r->right);
}
bool isSymmetric(TreeNode* root) {
    return isSym(root->left,root->right);
}

int main(){

}