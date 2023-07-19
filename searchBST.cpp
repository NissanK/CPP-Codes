#include<bits/stdc++.h>

using namespace std;

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

Node * insertBST(Node * root,int value){
    if(root == nullptr){
        return new Node(value);
    }
    if(root->val > value){
        root->left = insertBST(root->left,value);
    }
    else{
        root->right = insertBST(root->right,value);
    }
}

void inorder(Node * root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node* minValueNode(Node* root)
{
    Node* current = root;
  
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}
  
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    Node * head = nullptr;
    int choice = -1;
    while(choice != 0){
        cout<<"Enter the choice: 0.Break, 1.InsertNode, 2.DeleteNode, 3.Inorder: ";
        cin>>choice;
        if(choice == 1){
            int element;
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            head = insertBST(head,element);
        }
        else if(choice == 2){
            int element;
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            head = deleteNode(head,element);
        }
        else if(choice == 3){
            inorder(head);
            cout<<endl;
        }
    }
}