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

// int calcheight(node*root){
//     if(root==NULL)
//     return 0;
//     return max(calcheight(root->left),calcheight(root->right))+1;
// }

// int calcDiameter(node*root){
//     if(root==NULL)
//     return 0;
//     int lheight=calcheight(root->left);
//     int rheight=calcheight(root->right);
//     int currDiameter= lheight+rheight+1;

//     int lDiameter=calcDiameter(root->left);
//     int rDiameter=calcDiameter(root->right);
//     return max(currDiameter,max(lDiameter,rDiameter));
// }

int calcDiameterO(node*root, int *height){
    if(root==NULL){
        *height=0;
    return 0;
    }
    int lh=0,rh=0;
    int lDiameter=calcDiameterO(root->left , &lh);
    int rDiameter=calcDiameterO(root->right , &rh);
    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currDiameter,max(lDiameter,rDiameter));
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

    // cout<<calcDiameter(root)<<endl;
    int height=0;
    cout<<calcDiameterO(root,&height)<<endl;


    return 0;
}