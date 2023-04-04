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
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new Node(data);
    return;
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

void removeDuplicates(Node *head)
{
    map<int, int> mp;
    Node *temp = head;
    Node *newNext = NULL;
    Node *newHead = newNext;
    while (temp != NULL)
    {   
        if (mp.find(temp->data) != mp.end())
        {
            cout << "element found again " << temp->data << " freuqency " << mp[temp->data] << "\n";
        }
        else
        {
            if(newNext==NULL){
                newNext=temp;
                newHead=newNext;
            }else{
                cout<<"temp "<<temp->data<<" ";
                newNext->next=temp;
                newNext=newNext->next;
            }
            // push(newHead, temp->data);
        }
        mp[temp->data]++;
        temp = temp->next;
    }
    cout<<"\n";
    print(newHead);
}

int main()
{

    Node *head = NULL;
    push(head, 2);
    push(head, 2);
    push(head, 4);
    push(head, 5);
    push(head, 5);
    push(head, 2);
    push(head, 5);
    push(head, 5);
    push(head, 2);
    print(head);
    removeDuplicates(head);
    /* print(newHead); */
}