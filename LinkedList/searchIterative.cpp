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

void searchIterative(Node *head, int data)
{

    int pos = 0;
    int found = 0;
    while (head != NULL)
    {
        pos++;
        if (data == head->data)
        {
            found = 1;
            break;
        }
        head = head->next;
    }

    if (found == 1)
    {
        cout << "Data is found at following index : " << pos;
    }
    else
    {
        cout << "No data found";
    }
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

    searchIterative(head, 3);
}