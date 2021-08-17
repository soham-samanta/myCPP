#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void atTail(node*&head,int val){
    node*n=new node(val);
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

void atHead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    head=n;
}

void disp(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node*&head,int k){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node*&head){
    node*toDelete=head;
    head=head->next;
    delete toDelete;
}

void deletion(node*&head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node*toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

node* rev(node*&head){
    node*prev=NULL;
    node*curr=head;
    node*nextptr;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}

node* revRecur(node*&head){
    if(head==NULL||head->next==NULL)
    return head;
    node*newhead=revRecur(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node*revk(node*&head,int k){
    node*prev=NULL;
    node*curr=head;
    node*nextptr;
    int c=0;
    while(curr!=NULL&&c<k){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        c++;
    }
    if(nextptr!=NULL){
        head->next=revk(nextptr,k);
    }
    return prev;
}

void makeCycle(node*head,int pos){
    node*temp=head;
    node*startNode;
    int c=1;
    while(temp->next!=NULL){
        if(c==pos){
            startNode=temp;
        }
        temp=temp->next;
        c++;
    }
    temp->next=startNode;
}

bool detectCycle(node*head){
    node*fast=head,*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node*head){
    node*fast=head,*slow=head;
    do{
        fast=fast->next->next;
        slow=slow->next;
    }
    while (slow->next!=fast->next);
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}

int length(node*head){
    node*temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* appendK(node*head,int k){
    node*newHead;
    node*newTail;
    node*temp=head;
    int l=length(head);
    int c=1;
    while(temp->next!=NULL){
        if(c==(l-k)){
            newTail=temp;
        }
        if(c==(l-k+1)){
            newHead=temp;
        }
        temp=temp->next;
        c++;
    }
    newTail->next=NULL;
    temp->next=head;

    return newHead;
}

int main(){
    node*head=NULL;
    atTail(head,2);
    atTail(head,3);
    atTail(head,4);
    atTail(head,5);
    atTail(head,6);
    atHead(head,1);
    // disp(head);
    // cout<<search(head,7)<<endl;
    // deleteAtHead(head);
    // disp(head);
    // deletion(head,3);
    // disp(head);
    // node*newhead=rev(head);
    // disp(newhead);
    // node*newhead=revRecur(head);
    // disp(newhead);
    // node*newhead=revk(head,2);
    // disp(newhead);
    // makeCycle(head,3);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // disp(head);
    node*newhead=appendK(head,3);
    disp(newhead);
    

    return 0;
}