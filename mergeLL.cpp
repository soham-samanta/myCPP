#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node*&head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void disp(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* merge(node* &head1,node* &head2){
    node*p1=head1;
    node*p2=head2;
    node* dummynode=new node(-1);
    node*p3=dummynode;
    while(p1!=NULL&&p2!=NULL){
        if(p1->data>p2->data){
            p3->next=p2;
            p2=p2->next;
        }else{
            p3->next=p1;
            p1=p1->next;
        }
        p3=p3->next;
    }
        while(p1!=NULL){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        while(p2!=NULL){
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
    return dummynode->next;
}

node* mergeRecur(node*&head1,node*&head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node*result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecur(head1->next,head2);
    }else{
        result=head2;
        result->next=mergeRecur(head1,head2->next);
    }
    return result;
}

int main(){
    node*head1=NULL;
    node*head2=NULL;
    int a[]={1,4,5,7};
    for(int i=0;i<4;i++){
        insertAtTail(head1,a[i]);
    }
    int b[]={2,3,6};
    for(int i=0;i<3;i++){
        insertAtTail(head2,b[i]);
    }
    node*newHead=mergeRecur(head1,head2);
    disp(newHead);

    

}