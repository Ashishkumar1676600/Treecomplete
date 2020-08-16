//
//  main.cpp
//  treestart
//
//  Created by Ashish kumar on 16/08/20.
//  Copyright © 2020 Ashish kumar. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;
struct bstnode{
    int data;
    bstnode* right;
    bstnode* left;
};
bstnode* getnewnode(int data){
    bstnode* temp=new bstnode;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
bstnode* insert(bstnode* root,int data){
    if(root==NULL){
        root=getnewnode(data);
        return root;
        }
    if(data<=root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
bool search(bstnode* root,int data){
    if(root==NULL)
        return false;
    else if(data==root->data)
        return true;
    else if(data<=root->data)
        return search(root->left,data);
    else if(data>root->data)
        return search(root->right,data);
    else
        return false;
}
int findmin(bstnode* root){
    if(root==NULL){
        cout<<"tree is empty";
        return -1;
    }
    else if(root->left==NULL)
        return root->data;
    return findmin(root->left);
}
int findmax(bstnode* root){
    if(root==NULL){
        cout<<"tree is empty";
        return -1;
    }
    else if(root->right==NULL)
        return root->data;
    return findmax(root->right);
}
int height(bstnode* root){
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}
void levelordertraversal(bstnode* root){
    if(root==NULL)
        return;
    queue<bstnode* > q;
    q.push(root);
    while(!q.empty()){
        bstnode* current=q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
        q.pop();
    }
}
void inorder(bstnode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(bstnode* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(bstnode* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
bool bstutil(bstnode* root,int min,int max){
    if(root->data>min && root->data<max && bstutil(root->left,min,root->data) && bstutil(root->right,root->data,max))
            return true;
    else
        return false;
}
bool isbst(bstnode* root){
    return bstutil(root,INT_MIN,INT_MAX);
}
bstnode* Findmin(bstnode* root){
    if(root==NULL)
        return root;
    else if(root->right==NULL)
        return root;
    return Findmin(root->left);
}
bstnode* deletenode(bstnode* root,int data){
    if(root==NULL)
        return root;
    else if(data<root->data)
        deletenode(root->left,data);
    else if(data>root->data)
        deletenode(root->right,data);
    else{
        if(root->left==NULL && root->right==NULL){
            bstnode* temp=root;
            delete root;
            temp=NULL;
        }
        else if(root->right==NULL){
            bstnode* temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left==NULL){
            bstnode* temp=root;
            root=root->right;
            delete temp;
        }
        else{
            bstnode* temp=Findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    return root;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    bstnode* root=NULL;
    cout<<"tree process"<<endl;
    root=insert(root,20);
    root=insert(root,15);
    root=insert(root,25);
    root=insert(root,10);
    root=insert(root,17);
    root=insert(root,22);
    root=insert(root,28);
    cout<<"tree is done"<<endl;
    int n;
    cout<<"enter number to check"<<endl;
    cin>>n;
    if(search(root,n))
        cout<<"right";
    else
        cout<<"no";
    cout<<"min number in bst is "<<findmin(root)<<endl;
    cout<<"max number in bst is "<<findmax(root)<<endl;
    cout<<"find height of tree"<<height(root)<<endl;;
    cout<<"bfs is:";
    levelordertraversal(root);
    cout<<"\ninorder traversal";
    inorder(root);
    cout<<"\npreorder traversal";
    preorder(root);
    cout<<"\npostorder traversal";
    postorder(root);
    cout<<"\ncheck it is bst";
    /*if(isbst(root))
        cout<<"sure";
    else
        cout<<"nope";*/
    cout<<"\n delete node 20";
    root=deletenode(root,20);
    cout<<"new bfs is:";
    levelordertraversal(root);
    return 0;
}
