//
// Created by bhari on 21-10-2024.
//

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node * left;
    Node * right;
    Node(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
};
void preorder(Node * root){
    if(root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node * root){
    if(root) {
        preorder(root->left);
        cout << root->val << " ";
        preorder(root->right);
    }
}
void postorder(Node * root){
    if(root) {
        preorder(root->left);
        preorder(root->right);
        cout << root->val << " ";
    }
}


int main(){
    Node * root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    postorder(root);



}