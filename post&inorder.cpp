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

node* buildTree(int postorder[],int inorder[],int st,int end){
    static int idx=0;
    if(st>end)
    return NULL;
    int val=postorder[idx];
    idx--;
    node*curr=new node(val);
    if(st==end)
    return curr;
    int pos=search(inorder,st,end,val);
    curr->right=buildTree(postorder,inorder,pos+1,end);
    curr->left=buildTree(postorder,inorder,st,pos-1);
    return curr;
}

void inorderPrint(node*root){
    if(root==NULL)
    return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    node*root=buildTree(postorder,inorder,0,4);
    inorderPrint(root);

    return 0;
}