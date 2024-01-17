#include <iostream>
#include <climits>
#include "BinaryTree.h"
#include <vector>
#include <queue>
#include <stack>
using namespace std;


template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T data){
this->data=data;
left=NULL;
right=NULL;
    }
~BinaryTreeNode(){
    delete left;
    delete right;
}
};

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        next=NULL;

    }
};
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTree<int> *root) {
if(root==NULL){
	return vector<Node<int>*>();
}
vector<Node<int>*>* v=new vector<Node<int>*>();
queue<BinaryTree<int>*> q;
q.push(root);
q.push(NULL);
Node<int>* prev=NULL;
bool check=true;
while(!q.empty()){
BinaryTree<int>* front=q.front();

q.pop();
if(front==NULL){
check=true;
prev->next=NULL;
prev=NULL;
	if(!q.empty()){

		q.push(NULL);
	}
}
else{
	Node<int>* head=new Node<int>(front->data);
	if(check){
		    v->push_back(head);
            check=false;
	}
	if(prev){	prev->next=head;}
	prev=head;
	if(front->left){q.push(front->left);}
	if(front->right){q.push(front->right);}
}


}
return *v;
}

// Given a binary tree, print the zig zag order. 
// In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on.
// This means odd levels should get printed from left to right and even level right to left.
void zigZagOrder(BinaryTree<int> *root) {
    if(root==NULL){
	return;
}
queue<BinaryTree<int>*> q;
stack<BinaryTree<int>*> s;
q.push(root);
q.push(NULL);
bool check=true;
while(!q.empty()){
BinaryTree<int>* front=q.front();
if(check && front){
	cout<<front->data<<' ';
}
q.pop();
if(front==NULL){
if(!q.empty()){
	    if(!check){
			while(!s.empty()){
				cout<<s.top()->data<<' ';
				s.pop();
			}
		}
			cout<<endl;

	    if(check){
			check=false;
		}
		else{check=true;}
		q.push(NULL);
	}
}
else{
	if(front->left){
		if(check){
			s.push(front->left);
		}
		q.push(front->left);
		}
	if(front->right){
			if(check){
			s.push(front->right);
		}
		q.push(front->right);
		}
}
}
    if(!check){
			while(!s.empty()){
				cout<<s.top()->data<<' ';
				s.pop();
			}
		}
}

void elementsInrangek1k2k2(BinaryTree<int>* root,int k1,int k2){
    if(root==NULL){return;}
    if(root->data>=k1 & root->data<=k2){
        elementsInrangek1k2k2(root->left,k1,k2);
        cout<<root->data<<" ";
        elementsInrangek1k2k2(root->right,k1,k2);

    }
    if(root->data<k1){
        elementsInrangek1k2k2(root->right,k1,k2);

    }
        if(root->data>k1){
        elementsInrangek1k2k2(root->left,k1,k2);

    }
}

// O(n) rather than O(nlogn)
class BSTreturn{
public:
int min;
int max;
bool isBST;

};
BSTreturn isBSTcheck(BinaryTree<int>* root){
if(root==NULL){
    BSTreturn a;
    a.min=INT_MAX;
    a.max=INT_MAX;
    a.isBST=false;
    return a;
}
BSTreturn left=isBSTcheck(root->left);
BSTreturn right=isBSTcheck(root->right);
int MIN=min(root->data,min(left.min,right.min));
int MAX=max(root->data,max(left.max,right.max));
bool isbst  =(root->data >MIN && root->data<=MAX && left.isBST && right.isBST);
BSTreturn a;
a.min=MIN;
a.max=MAX;
a.isBST=isbst;
return a;

}

bool checkBST(BinaryTree<int>* root,int MIN=INT_MIN,int MAX=INT_MAX){
if(root==NULL){return true;}
if(root->data<MIN){return false;}
if(root->data>=MAX){return false;}
if(root->left){if(!checkBST(root->left,MIN,root->data)){return false;}}
if(root->right){if(!checkBST(root->right,root->data,MAX)){return false;}}
return true;
}


//Construct tree from a sorted array
BinaryTreeNode<int>* constructTree(int *input, int n) {
if(n==0){
	return NULL;
}
if(n==1){
	BinaryTreeNode<int>* node=new BinaryTreeNode<int>(input[0]);
	return node; 
}
BinaryTreeNode<int>* root;
BinaryTreeNode<int>* left;
BinaryTreeNode<int>* right;

if(n%2==0){
root=new BinaryTreeNode<int>(input[n/2-1]);
left=constructTree(input,  n/2-1);
right=constructTree(input+n/2,  n/2);
								}
else{
root=new BinaryTreeNode<int>(input[n/2]);
left=constructTree(input,  n/2);
right=constructTree(input+n/2+1,  n/2);
}
root->left=left;
root->right=right;
return root;
}


// Construct Sorted LL using balanced BST
pair<Node<int>*,Node<int>*> constructLinkedList1(BinaryTreeNode<int> *root) {

if(root==NULL){
	return pair<Node<int>*,Node<int>*>();
}
Node<int>* m=new Node<int>(root->data);
pair<Node<int>*,Node<int>*> left=constructLinkedList1(root->left);
pair<Node<int>*,Node<int>*> right=constructLinkedList1(root->right);
if(left.first && right.first){
	left.second->next=m;
	m->next=right.first;
	return pair<Node<int>*,Node<int>*>(left.first,right.second);
}
if(left.first){
	left.second->next=m;
	return pair<Node<int>*,Node<int>*>(left.first,m);
}
if(right.first){
	m->next=right.first;
	return pair<Node<int>*,Node<int>*>(m,right.second);
}
return pair<Node<int>*,Node<int>*>(m,m);
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
 pair<Node<int>*,Node<int>*> p=constructLinkedList1(root);
 return p.first;
}


// ######################## BST CLASS ########################
class BST {
    BinaryTreeNode<int>* root;
   public:
    BST() { 
root=NULL;
    }
private:
  BinaryTreeNode<int>* removeNode(BinaryTreeNode<int>* root,int data){
      if(root==NULL){
          return NULL;
      }
      if(root->data>data){
          removeNode(root->left, data);
      }
      if(root->data<data){
          removeNode(root->right, data);
      }
      if(root->data==data){
          if(root->left==NULL && root->right==NULL){
              delete root;
              return NULL;
          }
          else if(root->right==NULL && root->left!=NULL){
              BinaryTreeNode<int>* node=root->left;
              root->left=NULL;
              delete root;
              return node;
          }
         else if(root->right!=NULL && root->left==NULL){
              BinaryTreeNode<int>* node=root->right;
              root->right=NULL;
              delete root;
              return node;
          }
          else{
              BinaryTreeNode<int>* minNode=root->right;
              while(minNode->left!=NULL){
                  minNode=minNode->left;
              }
              root->data=minNode->data;
              root->right=removeNode(root->right, root->data);
              return root;
          }
      }
  }
    bool check(BinaryTreeNode<int>* root,int data){
		if(root==NULL){return false;}
        if(root->data==data){return true;}
        if(root->data<data){return check(root->right,data);}
        else{
            return check(root->left, data);
        }
    }
    void printBST(BinaryTreeNode<int>* root){
        if(root==NULL){return;}
        if(root->left && root->right){
        cout<<root->data<<":L:"<<root->left->data<<",R:"<<root->right->data<<endl;
        }
        else if(root->left){
            cout<<root->data<<":L:"<<root->left->data<<","<<endl;
        }
        else if(root->right){
            cout<<root->data<<":R:"<<root->right->data<<":"<<endl;

        }
        else if(root->left==NULL && root->right==NULL){
            cout<<root->data<<":"<<endl;
        }
        printBST(root->left);
        printBST(root->right);
    }
    BinaryTreeNode<int>* insertData(BinaryTreeNode<int>* root,int data){
        if(root==NULL){
return new BinaryTreeNode<int>(data);
        }
if(root->data>data){
    root->left=insertData(root->left,data);
    return root;
}
if(root->data<data){
   root->right= insertData(root->right,data);
    return root;
}
if(root->data==data){
            BinaryTreeNode<int>* left=root->left;
            BinaryTreeNode<int>* tem =new BinaryTreeNode<int>(data);
            root->left=tem;
            tem->left=left;
            return root;
}


    }
    public:

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
this->root=removeNode(root, data);
    }

    void print() { 
        printBST(root);
    }

    void insert(int data) { 
this->root=insertData(root,data);
    }


    bool search(int data) {
return check(root, data);
    }
};
