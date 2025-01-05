#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* FPS(Node* root){ // if root null then koi sub tree nahi hogi
    if (root==NULL){
        return NULL;
    }
    if (root->data>0){  // if current node data is +vee check its lefft right
        root->left=FPS(root->left);
        root->right=FPS(root->right);
        return root;
    }

    return FPS(root->left);
}
void printPreorder(Node* root) {
    if (root==NULL)
        return;
    cout <<root->data<< " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main() {
    Node* root=new Node(1);
    root->left=new Node(-2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(-5);
    root->right->left=new Node(-6);
    root->right->right=new Node(7);
    Node* positiveSubtree=FPS(root);
    cout << "Pre-order traversal of the first positive subtree:\n";
    printPreorder(positiveSubtree);
    return 0;
}
