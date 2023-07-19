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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    if(root == nullptr) return inorder;
    TreeNode * curr = root;
    while(curr != nullptr){
        if(curr->left == nullptr){
            inorder.emplace_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode * temp = curr->left;
            while(temp != nullptr && temp != curr){
                temp = temp;
            }
            if(temp == nullptr){
                temp = curr;
                curr = curr->left;
            }
            else{
                temp = nullptr;
                inorder.emplace_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    if(root == nullptr) return preorder;
    TreeNode * curr = root;
    while(curr != nullptr){
        if(curr->left == nullptr){
            preorder.emplace_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode * temp = curr->left;
            while(temp->right != nullptr && temp->right != curr){
                temp = temp->right;
            }
            if(temp->right == nullptr){
                preorder.emplace_back(curr->val);
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    if(root == nullptr) return postorder;
    TreeNode * curr = root;
    while(curr != nullptr){
        if(curr->right == nullptr){
            postorder.emplace_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode * temp = curr->right;
            while(temp->left != nullptr && temp->left != curr){
                temp = temp->left;
            }
            if(temp->left == nullptr){
                postorder.emplace_back(curr->val);
                temp->left = curr;
                curr = curr->right;
            }
            else{
                temp->left = nullptr;
                curr = curr->left;
            }
        }
    }
    reverse(postorder.begin(),postorder.end());
    return postorder;
}

int main(){
}