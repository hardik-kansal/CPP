#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
using namespace std;
int minTreeNode(BinaryTree<int>* root){
    if(root==NULL){
return INT_MAX;

    }
    return min(root->data,min(minTreeNode(root->left),minTreeNode(root->right)));
}



int maxTreeNode(BinaryTree<int>* root){
    if(root==NULL){
return INT_MIN;

    }
    return max(root->data,max(maxTreeNode(root->left),maxTreeNode(root->right)));
}


// CHeck-1 for Is BST
bool isBST(BinaryTree<int>* root){
    if(root==NULL){return true;}
    return root->data>maxTreeNode(root->left) && root->data<minTreeNode(root->right) && isBST(root->left) && isBST(root->right);
}

/*
pair<pair<int,int>,bool> isBST2(BinaryTree<int>* root){
    if(root==NULL){
        return pair<pair<int,int>,bool>(pair<int,int>(INT_MAX,INT_MIN),true);
    }
    pair<int,int> p=pair<int,int>();
}
check 3---using constraints of min and max


*/

// For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
 BinaryTreeNode<int>*  insertDuplicate(BinaryTreeNode<int> *root) {
   if(root==NULL){
       return NULL;
 }
   BinaryTreeNode<int>* node=new BinaryTreeNode<int>(root->data);
   BinaryTreeNode<int>* tem=root->left;
   root->left=node;
   node->left=insertDuplicate(tem);
   root->right=insertDuplicate(root->right);
  return root;
}
void insertDuplicateNode(BinaryTreeNode<int> *root) {
insertDuplicate(root);
}


int main(){

}