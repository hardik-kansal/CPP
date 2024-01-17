#include <iostream>
#include <climits>
#include "BinaryTree.h"
#include <vector>
#include <queue>
using namespace std;

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



int depth(BinaryTree<int>* root){
    if(root==NULL){return 0;}
    return 1+max(depth(root->left),depth(root->right));
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
void mirrorBinaryTree(BinaryTree<int>* root) {
    if (root == NULL) {
        return;
    }
    BinaryTree<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
vector<int> preOrder(BinaryTree<int> * root){
if(root==NULL){
    return vector<int>();
}
vector<int> v;
v.push_back(root->data);
vector<int> left=preOrder(root->left);
for(int i=0;i<left.size();i++){
    v.push_back(left[i]);
}
vector<int> right=preOrder(root->right);
for(int i=0;i<right.size();i++){
    v.push_back(right[i]);
}
return v;
}

BinaryTree<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
int rootData=postorder[postLength-1];
BinaryTree<int>* root=new BinaryTree<int>(rootData);
int l=0;
for(int i=0;i<inLength;i++){
    if(inorder[i]==rootData){
        break;
}
        l++;

}
BinaryTree<int>* left=buildTree(postorder,l,inorder,l);
BinaryTree<int>* right=buildTree(postorder+l,postLength-l-1,inorder+l+1,inLength);

if(left){
    root->left=left;
}
if(right){
    root->right=right;
}
return root;


}
void printLevelWise(BinaryTree<int> *root) {
if(root==NULL){
	return;
}
queue<BinaryTree<int>*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
BinaryTree<int>* front=q.front();
q.pop();
if(front==NULL){
	cout<<endl;
	if(!q.empty()){
		q.push(NULL);
	}
}
else{
	cout<<front->data<<' ';
	if(front->left){q.push(front->left);}
    if(front->right){q.push(front->right);}

}
}
}

void printLevel(BinaryTree<int>* root){
    if(root==NULL){return;}
    queue<BinaryTree<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        BinaryTree<int>* node=q.front();
        q.pop();
        if(node==NULL){
            cout<<endl;

            if(!q.empty()){
            q.push(NULL);
            }
        }
        
        if(root->left){q.push(root->left);}
       if(root->right){q.push(root->right);}        
       cout<<node->data<<" ";

    }
}

int main(){
   BinaryTree<int>*node=takeInputRecursive();
}