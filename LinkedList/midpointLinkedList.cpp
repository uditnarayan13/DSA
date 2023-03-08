#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

Node* findMidpoint(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast!= NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}
int main()
{ 
    Node* head = NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);

    // print(head);

    Node* midPoint = findMidpoint(head);
    cout<<" Midpoint : "<<midPoint->data;


}