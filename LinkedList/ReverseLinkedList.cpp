#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};

void push(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void reverseIterative(Node *&head){
    Node* prev = NULL;
    Node* curr = head;
    Node* currNext = head->next;

    while(curr!=NULL && currNext!=NULL){
        Node* temp = currNext->next;
        currNext->next=curr;
        curr->next=prev;

        prev=curr;
        curr=currNext;
        currNext=temp;
    }
    head=curr;

}

Node* recursiveReverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newHead = recursiveReverse(head->next);
    Node* current = head;
    current->next->next =current;
    current->next=NULL;
    return newHead;
}

int main()
{
    Node *head = NULL;
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    print(head);
    reverseIterative(head);
    print(head);
    head=recursiveReverse(head);
    print(head);
}