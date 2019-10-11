#include<iostream>
#include<fstream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

/*void gen_input(int arr[],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      arr[i]=(rand()%50)+50;
    }
  ofstream myfile;
  myfile.open("inputavl.txt");
  for(i=0;i<n;i++)
    {
      myfile<<arr[i]<<" ";
    }
    }*/

class Node
{
  public:
  int key,height;
  Node *left;
  Node *right;
};

int max(int a,int b)
{
  return (a>b)?a:b;
}

int height(Node *N)
{
  if(N==NULL)
    return 0;
  return N->height;
}

Node* newNode(int key)
{
  Node* node=new Node();
  node->key=key;
  node->left=NULL;
  node->right=NULL;
  node->height=1;
  return (node);
}

Node *rightRotate(Node *y)
{
  Node *x=y->left;
  Node *T2=x->right;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
  return x;
}

Node *leftRotate(Node *x)
{
  Node *y=x->right;
  Node *T2=y->left;
  x->height=max(height(x->left),height(x->right))+1;
  y->height=max(height(y->left),height(y->right))+1;
  return y;
}

int getBalance(Node* N)
{
  if(N==NULL)
    return 0;
  return height(N->left)-height(N->right);
}

Node *insert(Node* node,int key)
{
  if(node==NULL)
    return (newNode(key));
  if(key<node->key)
    node->left=insert(node->left,key);
  else if(key>node->key)
    node->right=insert(node->right,key);
  else 
    return node;
  node->height=1+max(height(node->left),height(node->right));

  int balance=getBalance(node);
  if(balance>1 && key<node->left->key)
    return rightRotate(node);

  if(balance<-1 && key>node->right->key)
    return leftRotate(node);

  if(balance>1 && key>node->left->key)
    {
      node->left=leftRotate(node->left);
      return rightRotate(node);
    }

  if(balance<-1 && key<node->right->key)
    {
      node->right=rightRotate(node->right);
      return leftRotate(node);
    }
  return node;
}

void printarr(int arr[], int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
  cout<<endl;
}

void inOrder(Node *root)
{
  if(root!=NULL)
    {
    
      inOrder(root->left);
      cout<<root->key<<" ";
      inOrder(root->right);
    }
}


int main()
{
  int n,i,x;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
    {
      arr[i]=(rand()%50)+50;
    }
  ofstream myfile;
  myfile.open("inputavl.txt");
  for(i=0;i<n;i++)
    {
      myfile<<arr[i]<<" ";
    }

  Node *root=NULL;
 
  ifstream infile;
  infile.open("inputavl.txt");
  while(i<n)
    {
      infile>>arr[i];
      i++;
    }
  infile.close();
  printarr(arr,n);
  for(i=0;i<n;i++)
    {
      root=insert(root,arr[i]);
    }
  
  inOrder(root);
  printarr(arr,n);
  ofstream myfile;
  myfile.open("outputavl.txt");

  return 0;
}
  
