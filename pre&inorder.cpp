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

int search(int inorder[],int st,int end,int val){
    for(int i=st;i<=end;i++){
        if(inorder[i]==val)
        return i;
    }
    return -1;
}

node*buildTree(int preorder[],int inorder[],int st,int end){
    static int idx=0;
    if(st>end)
    return NULL;
    int val=preorder[idx];
    idx++;
    node*curr=new node(val);
    if(st==end)
    return curr;
    int pos=search(inorder,st,end,val);
    curr->left=buildTree(preorder,inorder,st,pos-1);
    curr->right=buildTree(preorder,inorder,pos+1,end);
    return curr;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    node*root=buildTree(preorder,inorder,0,4);
    inorderPrint(root);

    return 0;
}