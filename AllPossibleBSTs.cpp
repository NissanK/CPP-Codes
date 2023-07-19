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

// program to build all possible BSTs
// https://youtu.be/1ZAotQGnbi4

vector<TreeNode * > buildBST(int st,int end){

    vector<TreeNode *> trees;

    if(st>end){
        trees.emplace_back(nullptr);
        return trees;
    }

    for(int i = st;i<=end;i++){

        vector<TreeNode *> leftSubtrees = buildBST(st,i-1);
        vector<TreeNode *> rightSubtrees = buildBST(i+1,end);

        for(int j = 0;j<leftSubtrees.size();j++){
            TreeNode * left = leftSubtrees[j];
            for(int k = 0;k<rightSubtrees.size();k++){
                TreeNode * right = rightSubtrees[k];
                TreeNode * root = new TreeNode(i);

                root->right = right;
                root->left = left;
                trees.emplace_back(root);
            }
        }
    }
    return trees;
}


void preorder(TreeNode * root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    vector<TreeNode *> trees = buildBST(1,4);

    for(int i = 0;i<trees.size();i++){
        cout<<i+1<<" : ";
        preorder(trees[i]);
        cout<<endl;
    }
}