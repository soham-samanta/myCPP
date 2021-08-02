#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// int height(node*root){
//     if(root==NULL)
//     return 0;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     return max(lh,rh)+1;
// }

// bool isbalanced(node*root){
//     if(root=NULL)
//     return true;
//     if(isbalanced(root->left)==false)
//     return false;
//     if(isbalanced(root->right)==false)
//     return false;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     if(abs(lh-rh)<=1)
//     return true;
//     else
//     return false;
// }

bool isbalanced(node*root, int*height){
    if(root==NULL)
    return true;
    int lh=0,rh=0;
    if(isbalanced(root->left,&lh)==false)
    return false;
    if(isbalanced(root->right,&rh)==false)
    return false;

    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;

}

int main(){
    node* root= new node(1);
    root->left=new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);

    // if(isbalanced(root))
    // cout<<"Tree is balanced"<<endl;
    // else
    // cout<<"Tree is not balanced"<<endl;

    int height=0;
    if(isbalanced(root,&height)==true)
    cout<<"balanced"<<endl;
    else
    cout<<"not balanced";

    return 0;
}