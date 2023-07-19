#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

Node * buildBST(vector<int> & preorder, int * preIDX,int key,int min,int max,int n){
    if(*preIDX >=n){
        return nullptr;
    }

    TreeNode * root = nullptr;

    if(key > min && key < max){
        root = new TreeNode(key);

        *preIDX += 1;

        if(*preIDX < n){
            root->left = buildBST(preorder,preIDX,preorder[*preIDX],min,key,n);
        }
        if(*preIDX< n){
            root->right = buildBST(preorder,preIDX,preorder[*preIDX],key,max,n);
        }
    }

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int preIDX = 0;
    int n = preorder.size();
    TreeNode * head = buildBST(preorder,&preIDX,preorder[0],INT_MIN,INT_MAX,n);
    return head;
}

int main(){

}