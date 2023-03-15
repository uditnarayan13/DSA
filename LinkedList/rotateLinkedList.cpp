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
        this->next = NULL;
    }
};

void push(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void rotateList(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next->next = head;
    head = prev->next;
    prev->next = NULL;
}

void leftRotateList(Node *&head)
{
    Node *curr = head;
    Node *last = head;
    Node *newHead = head->next;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = head;
    head->next = NULL;
    head = newHead;
}

Node *newleftRotateList(Node *head, int k)
{
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    while (k--)
    {
        Node *curr = head;
        Node *newHead = head->next;

        last->next = head;
        last = head;
        head->next = NULL;
        head = newHead;
    }

    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "\n";
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
    rotateList(head);
    head = newleftRotateList(head, 2);
    print(head);
}