#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void disp(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void atHead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=NULL;
    head=n;
}

void atTail(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        atHead(head,val);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(node*&head){
    node*todelete = head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletion(node*&head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    int c=1;
    while(temp!=NULL && c!=pos){
        temp=temp->next;
        c++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}

int main(){
    node*head=NULL;
    atTail(head,2);
    atTail(head,3);
    atTail(head,4);
    atTail(head,5);
    atHead(head,1);
    disp(head);
    deletion(head,3);
    disp(head);
    return 0;
}