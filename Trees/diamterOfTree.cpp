#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
    public :
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class heightDiameter{
    public :
    int height;
    int diameter;
};

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);
    root->left = buildTree();
    root->right=buildTree();
    return root;

}

void printTree(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int heightOfTree(Node* root){

    if(root==NULL){
        return 0;
    }

    int lsh = heightOfTree(root->left);
    int rsh = heightOfTree(root->right);

    return max(lsh,rsh)+1;

}
/**
 * Diameter of tree : 
 *  1. diameter and height of root which is null is 0
 *  2. height of a node is calculated
 *  3.  diamater of node is calculated :
 *      3.1 total number of nodes (sum of height of left tree and  right tree).
 *      3.2 Diameter of left-sub-tree.
 *      3.3 Diameter of right-sub-tree.
 */

heightDiameter diameter(Node* root){
    heightDiameter dia ;
    if(root==NULL){
        dia.height=0;
        dia.diameter=0;
        return dia;
    }

    heightDiameter leftDiameter = diameter(root->left);
    heightDiameter rightDiameter = diameter(root->right);

    dia.height = max(leftDiameter.height,rightDiameter.height)+1;
    int optionalDiameter= max(leftDiameter.diameter,rightDiameter.diameter);
    dia.diameter = max(leftDiameter.height+rightDiameter.height,optionalDiameter);

    return dia; 
}

int main(){
    Node* root = NULL;
    root=buildTree();

    heightDiameter result = diameter(root);
    cout<<"Diameter of tree : "<<result.diameter<<" height of tree : "<<result.height<<"\n";
    
}