#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 1. Deleting at Head 
   2. Deleting at Middle
   3. Deleting at Tail
*/
class Node {
public : 
int data;
Node* next;

Node(int data){
    this->data = data;
}
};

void push(Node *&head, int data){
    Node * temp =new Node(data);
    temp->next = head;
    head= temp;
}

void deleteAtHead(Node *&head){
    if(head ==NULL){
        return ;
    }
    Node* temp = head;
    head=head->next;
    delete temp;
}

void deleteAtMiddle(Node* head , int pos){
    Node* prev=head;
    Node* curr=head->next;
    while(pos-2>=0 && prev!=NULL && curr!=NULL){
        prev=prev->next;
        curr=curr->next;
      
        pos--;
    }
    Node* temp = curr;
    prev->next = curr->next;

    delete temp;

}

void deleteAtTail(Node* head){
    while(head->next->next!=NULL){
        head=head->next;
    }
    Node* temp = head->next;
    head->next=NULL;
    delete temp;
    return;
}

void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int main(){
    Node * head =NULL;
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);
    push(head,6);
    print(head);
    deleteAtTail(head);
    print(head);
    /* deleteAtMiddle(head,2);
    print(head);

    print(head);
    deleteAtHead(head);
    print(head); */

}