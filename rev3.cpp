#include <iostream>
#include<string>
using namespace std;

// when mapped out it's a Tournament Bracket which are just {1Fv3nT3drCr375}3_S

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void encode(struct Node* node, string flag)
{
    if (node == NULL)
        return;
    encode(node->left, flag);
    encode(node->right, flag);
    cout << flag[node->data] << "";
}

int main()
{
    // HINT: this encoding only rearranges characters i.e. it does not add remove or change any character
    string flag;
    cout << "Enter Flag to be encoded: ";
    cin >> flag;
    struct Node* root = new Node(0);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->left->left = new Node(4);
    root->left->left->left->right = new Node(5);
    root->left->left->right = new Node(6);
    root->left->left->right->left = new Node(7);
    root->left->left->right->right = new Node(8); 
    root->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->left = new Node(11);
    root->left->right->right = new Node(12);
    root->right = new Node(13);
    root->right->left = new Node(14);
    root->right->left->left = new Node(15);
    root->right->left->right = new Node(16);
    root->right->right = new Node(17);
    root->right->right->left = new Node(18);
    root->right->right->right = new Node(19);
    encode(root, flag);
    cout << "\n";
    return 0;
}