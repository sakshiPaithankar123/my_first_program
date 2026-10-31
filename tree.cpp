#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*left;
    node*right;

    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

class BST
{
    private:
    node*root;

    node*insert(node*root,int val)
    {
        if(root==NULL)
        {
            return new node(val);
        }
        if(val<root->data)
        {
            root->left=
            insert(root->left,val);
        }
        else if(val>root->data)
        {
            root->right=
            insert(root->right,val);
        }
        return root;
    }
    void inorder(node*root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void preorder(node*root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node*root)
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
    public:
    BST()
    {
        root=NULL;
    }
    void insert(int val)
    {
        root=insert(root,val);
    }
    void inorder()
    {
        cout<<"inorder traversal:";
        inorder(root);
        cout<<endl;
    }
    void preorder()
    {
        cout<<"preorder traversal:";
        preorder(root);
        cout<<endl;
    }
    void postorder()
    {
        cout<<"postorder traversal:";
        postorder(root);
        cout<<endl;
    }
};

int main()
{
    BST tree;

    tree.insert(66);
    tree.insert(44);
    tree.insert(88);
    tree.insert(92);
    tree.insert(100);
    tree.insert(140);
    tree.insert(71);

    tree.inorder();
    tree.preorder();
    tree.postorder();

    return 0;
}

//PS D:\tejaswini> g++ tree.cpp
//PS D:\tejaswini> ./a.exe
//inorder traversal:44 66 71 88 92 100 140 
//preorder traversal:66 44 88 71 92 100 140 
//postorder traversal:44 71 140 100 92 88 66 
//PS D:\tejaswini> 