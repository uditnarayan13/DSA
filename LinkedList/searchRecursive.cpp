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

void searchRecursive(Node *head, int data,int pos)
{

    if(head==NULL){
        cout<<"Not found : "<<data;
        return;
    }

    if(head->data == data){
        cout<<"Element found at this index : "<<pos;
        return;
    }

    searchRecursive(head->next,data,pos+1);
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

    searchRecursive(head, 1,1);
}