#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

class Node
{
  public:
    char data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data)
    {
      this->data = data;
    }
};

void createTree(Node* root)
{
  Node* b = new Node('b');
  Node* g = new Node('g');
  Node* a = new Node('a');
  Node* d = new Node('d');
  Node* i = new Node('i');
  Node* c = new Node('c');
  Node* e = new Node('e');
  Node* h = new Node('h');

  root->left = b;
  root->right = g;
  b->left = a;
  b->right = d;
  d->left = c;
  d->right = e;
  g->right = i;
  i->left = h;
};

//create an symmetric tree
Node* createTree1()
{
  Node* root = new Node('f');
  Node* b = new Node('1');
  Node* g = new Node('1');
  Node* a = new Node('3');
  Node* d = new Node('4');
  Node* i = new Node('3');
  Node* c = new Node('c');
  Node* e = new Node('4');
  Node* h = new Node('h');

  root->left = b;
  root->right = g;
  b->left = a;
  b->right = d;
  g->left = e;
  g->right = i;
  
  return root;
};

//create an unsymmetric tree
Node* createTree2()
{
  Node* root = new Node('f');
  Node* b = new Node('1');
  Node* g = new Node('1');
  Node* a = new Node('3');
  Node* d = new Node('3');
  Node* i = new Node('4');
  Node* c = new Node('c');
  Node* e = new Node('4');
  Node* h = new Node('h');

  root->left = b;
  root->right = g;
  b->left = a;
  b->right = d;
  g->left = e;
  g->right = i;
  
  return root;
};

//create an number tree
Node* createTree3()
{
  Node* n0 = new Node(5);
  Node* n1 = new Node(4);
  Node* n2 = new Node(8);
  Node* n3 = new Node(11);
  Node* n4 = new Node(13);
  Node* n5 = new Node(4);
  Node* n6 = new Node(7);
  Node* n7 = new Node(2);
  Node* n8 = new Node(1);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n3->left = n6;
  n3->right = n7;
  n2->left = n4;
  n2->right = n5;
  n5->right = n8;
  
  return n0;
};


//create tree form list
// Node* create_tree_from_list(int* num_list, int length)
// {
//   int level = 0;
//   while(pow(2,level) < length){
//   }
// }


class Traversal
{
  public:
    void preOrder(Node* tree)
    {
      cout<<tree->data<<endl;
      if (tree->left){
        preOrder(tree->left);
      }
      if (tree->right){
        preOrder(tree->right);
      }
    }

    void inOrder(Node* tree)
    {
      if (tree->left){
        inOrder(tree->left);
      }
      cout<<tree->data<<endl;
      if (tree->right){
        inOrder(tree->right);
      }
    }

    void postOrder(Node* tree)
    {
      if (tree->left){
        postOrder(tree->left);
      }
      if (tree->right){
        postOrder(tree->right);
      }
      cout<<tree->data<<endl;
    }

    void levelOrder(Node* tree)
    {
      queue< Node* > q;
      q.push(tree);

      while (q.size()>0)
      {
        Node* tempt = q.front();
        cout<<tempt->data<<endl;
        if (tempt->left)
        {
          q.push(tempt->left);
        }
        if (tempt->right)
        {
          q.push(tempt->right);
        }
        q.pop();
      }
      
    }

    int maxDepth(Node* tree)
    {
      if (!tree)
      {
        return 0;
      }   
      return max(maxDepth(tree->left)+1, maxDepth(tree->right)+1);
      
    }

    bool isSymmetric(Node* tree)
    {
      return _isSymmetric(tree->left, tree->right);
    }

    bool _isSymmetric(Node* left, Node* right)
    {
      if (NULL == left && NULL == right)
      {
        return true;
      } else if (NULL == left && NULL != right)
      {
        return false;
      } else if (NULL != left && NULL == right)
      {
        return true;
      } else if(_isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left) && left->data == right->data)
      {
        return true;
      } else {
        return false;
      }
    }

    bool hasPathSum(Node* tree, int target)
    {
      queue<int> q;
      _hasPathSum(tree, target, q);
      while(q.size()>0){
        if (q.front() == target){
          return true;
        }
        q.pop();
      }
      return false;

    }
    
    void _hasPathSum(Node* tree, int target, queue<int>& q)
    {
      if (tree->left){
        tree->left->data += tree->data;
        _hasPathSum(tree->left, target, q);
      }
      if (tree->right){
        tree->right->data += tree->data;
        _hasPathSum(tree->right, target, q);
      }
      if (NULL==tree->left && NULL==tree->right){
        q.push(tree->data);
      }
    }
};

int main()
{
  Node* root = new Node('f');
  createTree(root);

  Traversal* tv = new Traversal();
  // tv->preOrder(root);
  // tv->inOrder(root);
  // tv->postOrder(root);
  // tv->levelOrder(root);
  
  // cout<<tv->maxDepth(root)<<endl;
  
  // cout<<tv->isSymmetric(root)<<endl;
  // cout<<tv->isSymmetric(createTree1())<<endl;
  // cout<<tv->isSymmetric(createTree2())<<endl;
  
  cout<<tv->hasPathSum(createTree3(), 22)<<endl;
  cout<<tv->hasPathSum(createTree3(), 21)<<endl;


}