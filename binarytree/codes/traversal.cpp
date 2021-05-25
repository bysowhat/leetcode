#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data){
       this->data = data;
    }
};


Node* createTree()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    
    return root;
}


void preOrder(Node* root)
{
    cout << root->data;
    if (root->left != NULL){
        preOrder(root->left);
    }
    if (root->right != NULL){
        preOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if (root->left != NULL){
        postOrder(root->left);
    }
    if (root->right != NULL){
        postOrder(root->right);
    }
    cout << root->data;
}

void inOrder(Node* root)
{
    if (root->left != NULL){
        inOrder(root->left);
    }
    cout << root->data;
    if (root->right != NULL){
        inOrder(root->right);
    }
}

void levelOrder(Node* root)
{
    queue< Node* > q;
    if( root!=NULL )
    {
        q.push(root);
    }
    while(q.size() != 0)
    {
        cout << q.front()->data;
        if (q.front()->left != NULL)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right != NULL)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
}

int main()
{
   //-> is a shorthand for (*x).field, where x is a pointer to a variable of type struct account
   Node* root = createTree();

   preOrder(root);
   cout << "******************" << endl;
   postOrder(root);
   cout << "******************" << endl;
   inOrder(root);
   cout << "******************" << endl;
   levelOrder(root);
   cout << "******************" << endl;
}
