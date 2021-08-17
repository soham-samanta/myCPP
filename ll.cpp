#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class node{
    public:
    int data;
    node* next;
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

bool search(node*&head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node*&head){
    node*todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node*&head,int val){
    if(head==NULL || head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
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
    if(head==NULL or head->next==NULL){
        return head;
    }
    node* newHead=revRecur(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

node* revk(node*&head,int k){
    node* prev=NULL;
    node*curr=head;
    node* nextptr;
    int c=0;
    while(curr!=NULL && c<k){
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

void makeCycle(node*&head,int pos){
    node*temp=head;
    node*startnode;
    int c=1;
    while(temp->next!=NULL){
        if(c==pos){
            startnode=temp;
        }
        temp=temp->next;
        c++;
    }
    temp->next=startnode;
}

bool detectCycle(node*&head){
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        return true;
    }
    return false;
}

void removeCycle(node*&head){
    node*fast=head;
    node*slow=head;
    do
    {
        fast=fast->next->next;
        slow=slow->next;
    } while (slow->next!=fast->next);{
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}

int length(node*&head){
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* kappend(node*&head,int k){
    node*newTail;
    node*newHead;
    node* tail=head;
    int l=length(head);
    int c=1;
    while(tail->next!=NULL){
        if(c==l-k)
        newTail=tail;
        if(c==l-k+1)
        newHead=tail;
        tail=tail->next;
        c++;
    }
    newTail->next=NULL;
    tail->next=head;
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
    // cout<<search(head,4)<<endl;
    // deletion(head,3);
    // disp(head);
    // deleteAtHead(head);
    disp(head);
    node* newHead=revRecur(head);
    disp(newHead);
    // int k=2;
    // node* newhead=revk(head,k);
    // disp(newhead);
    //makeCycle(head,3);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // node*newHead=kappend(head,3);
    // disp(newHead);

    return 0;
}