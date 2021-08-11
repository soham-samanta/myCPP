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

void disp(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void tail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void athead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

bool search(node* &head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
    }
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

node* reverse(node*&head){
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

node* revrecur(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=revrecur(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* revk(node* &head,int k){
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

void makecycle(node*&head,int pos){
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

bool detectcycle(node*&head){
    node*fast=head;
    node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removecycle(node*&head){
    node*slow=head;
    node*fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow->next!=fast->next);{
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main(){
    node* head=NULL;

    tail(head,2);
    tail(head,3);
    tail(head,4);
    tail(head,5);
    tail(head,6);
    athead(head,1);
    disp(head);
    // cout<<search(head,9)<<endl;

    // deletion(head,3);
    // deleteAtHead(head);
    // disp(head);

    // node* newhead=revrecur(head);
    // disp(newhead);

    // int k=2;
    // node* newhead=revk(head,k);
    // disp(newhead);

    // makecycle(head,3);
    // cout<<detectcycle(head)<<endl;
    // removecycle(head);
    cout<<detectcycle(head)<<endl;


return 0;
}