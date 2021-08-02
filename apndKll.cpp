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

int lenght(node*&head){
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;   
        l++; 
    }
    return l;
}

node* kappend(node* &head,int k){
    node* newTail;
    node* newHead;
    node*tail=head;
    int l=lenght(head);
    k=k%l;
    int c=1;
    while(tail->next!=NULL){
        if(c==l-k){
            newTail=tail;
        }
        if(c==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        c++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

int main(){
    node*head=NULL;
    int a[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,a[i]);
    }
    disp(head);
    node* newHead=kappend(head,3);
    disp(newHead);

}