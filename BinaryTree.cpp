#include <iostream>
#include <climits>
#include "BinaryTree.h"
using namespace std;

int depth(BinaryTree<int>* root){
    if(root==NULL){return 0;}
    int ans=1;
    return ans+max(depth(root->left),depth(root->right));
}





int height(BinaryTree<int>* root){
    if(root==NULL){return 0;}
    int ans=1;
    return ans+max(depth(root->left),depth(root->right));
}
// 3 cases--
// 1)lh+rh
// 2)diameter(root->left)
// 3)diamter(root->right)
int diameterTree(BinaryTree<int>* root){
    if(root==NULL){return 0;}
    int option1=height(root->left)+height(root->right);
    int option2=diameterTree(root->left);
    int option3=diameterTree(root->right);
    return max(option1,max(option2,option3));  // max takes two args.
    
}
// if tree is linear => T(n)=kn(height)+T(n-1)(diamter)----------------------------------------------------------------O(nlogn)
// if tree is balanced => T(n)=kn+2T(n/2)  ----------------------------------------------------------------O(n square)
// => O(nh) where h is complexity of height & log(n) in balanced(by maths :) and n in linear.

pair<int,int> heightDiameter(BinaryTree<int>* root){
    if(root==NULL){
        return pair<int,int>(0,0);
    }
    pair<int,int> left=heightDiameter(root->left);
    pair<int,int> right=heightDiameter(root->right);
    return pair<int,int>(1+max(left.first,right.first),max(left.first+right.first,max(left.second,right.second)));
}// ----------------o(n)
BinaryTree<int>* takeInputRecursive(){
    int rootData;
cout<<"Enter Root data"<<endl;
cin>>rootData;
if(rootData==-1){
    return NULL;
}
BinaryTree<int>* node = new BinaryTree<int>(rootData);
BinaryTree<int>* left=takeInputRecursive();
BinaryTree<int>* right=takeInputRecursive();
if(left){
    node->left = left;

}
if(right){
    node->right = right;
}
return node;
}

int main(){
   BinaryTree<int>*node=takeInputRecursive();
}