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

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> TreeOrder;

    if(root==nullptr){
        return TreeOrder;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    vector<int> level;
    while(!q.empty()){
        if(q.front()==nullptr){
            TreeOrder.emplace_back(level);
            level.clear();
            q.pop();
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            level.emplace_back(q.front()->val);

            if(q.front()->left != nullptr){
                q.push(q.front()->left);
            }

            if(q.front()->right != nullptr){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    return TreeOrder;
}

int maxLevelSum(TreeNode* root) {

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int maxSum = INT_MIN;
    int Sum = 0;
    int level = 1;
    int maxLevel = 0;
    while(!q.empty()){
        if(q.front()==nullptr){
            if(Sum>maxSum){
                maxLevel = level;
                maxSum = Sum;
            }
            Sum = 0;
            level ++;
            q.pop();
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            Sum += q.front()->val;
            if(q.front()->left != nullptr){
                q.push(q.front()->left);
            }

            if(q.front()->right != nullptr){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    return maxLevel;
}

int sumOfLeftLeaves(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }
    int sum=0;
    if(root->left && root->left->left==nullptr && root->left->right==nullptr){
        sum=sum+root->left->val;
    }
    sum=sum+sumOfLeftLeaves(root->left);
    sum=sum+sumOfLeftLeaves(root->right);
    return sum;
}

int maxDepth(TreeNode* root){

    if(root == nullptr){
        return 0;
    }

    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }

    int lheight = maxDepth(root->left);
    int rheight  = maxDepth(root->right);

    int currDia = lheight + rheight + 1;

    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);

    return max(currDia,max(left,right));
}

int diameterTree(TreeNode * root, int * height){
    if(root==nullptr){
        *height = 0;
        return 0;
    }

    int lh = 0;int rh = 0;

    int lDia = diameterTree(root->left,&lh);
    int rDia = diameterTree(root->right,&rh);
    int currDia = lh + rh + 1;
    * height = max(lh,rh) + 1;

    return max(currDia,max(lDia,rDia));
}

bool isBalancedCheck(TreeNode * root, int * height){
    if(root==nullptr){
        *height = 0;
        return true;
    }

    int lh = 0;int rh = 0;

    if(isBalancedCheck(root->left,&lh)==0 || isBalancedCheck(root->right,&rh)==0){
        return false;
    }
    *height = max(lh,rh) + 1;
    if(abs(lh-rh)>1){
        return false;
    }
    return true;
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> RightView;
    if(root==nullptr){
        return RightView;
    }

    queue<TreeNode *> q;

    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            TreeNode * curr = q.front();
            q.pop();

            if(i == 0){
                RightView.emplace_back(curr->val);
            }

            if(curr->left!=nullptr){
                q.push(curr->left);
            }

            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
    }

    return RightView;
}

TreeNode * LCA(TreeNode * root,int n1,int n2){
    if(root==nullptr){
        return root;
    }

    if(root->val==n1 || root->val==n2){
        return root;
    }

    TreeNode * left = LCA(root->left,n1,n2);
    TreeNode * right = LCA(root->right,n1,n2);

    if(left!=nullptr && right!=nullptr){
        return root;
    }

    else if(left==nullptr && right == nullptr){
        return nullptr;
    }

    else if(left!=nullptr){
        return left;
    }
    else{
        return right;
    }
}

void flatten(TreeNode* root) {
    if(root==nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
   if(root->left != nullptr){
       flatten(root->left);

       TreeNode * temp = root->right;
       root->right = root->left;
       root->left = nullptr;
       TreeNode * t = root->right;
       while(t->right != nullptr){
           t = t->right;
       }

       t->right = temp;
   }

   flatten(root->right);
}

int maxPathSumUtil(TreeNode * root,int &ans){
    if(root==nullptr){
        return 0;
    }

    int ls = maxPathSumUtil(root->left,ans);
    int rs = maxPathSumUtil(root->right,ans);

    int nodeMax = max(max(root->val,root->val + ls + rs),
                        max(root->val + ls,root->val + rs));

    ans = max(ans,nodeMax);

    int singlePath = max(max(root->val + ls,root->val + rs),root->val);
    return singlePath;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;

    maxPathSumUtil(root,ans);

    return ans;

}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
}