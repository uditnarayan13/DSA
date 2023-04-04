#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
    return;
}
int heightofTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lsh = heightofTree(root->left);
    int rsh = heightofTree(root->right);

    return max(lsh, rsh) + 1;
}

void printKLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}

void printAllLevel(Node *root)
{
    int height = heightofTree(root);
    for (int i = 1; i <= height; i++)
    {
        printKLevel(root, i);
        cout << "\n";
    }
}
void showq(queue<Node*> gq)
{
    queue<Node*> g = gq;
    while (!g.empty()) {
        Node* temp = g.front();
        if(temp!=NULL){
             cout << '\t' << temp->data;
        }else{
            cout << '\t' << -1;
        }
       
        g.pop();
    }
    cout << '\n';
}

void bfsRoot(Node *root)
{
    queue<Node *> q;
    if (root != NULL)
    {
        q.push(root);
    }
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {   
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree();
    /*  print(root); */

    /* printKLevel(root, 3); */
    /*  printAllLevel(root); */
    bfsRoot(root);
}
