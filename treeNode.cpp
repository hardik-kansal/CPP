#include <iostream>
#include "treeNode.h"
#include <queue>
#include <vector>
using namespace std;


TreeNode<int>* inputLevelWise(){
   cout<<"Enter root data"<<endl;
   int rootData=0;
   int num=0;
   queue<TreeNode<int>*> q;
cin>>rootData;
TreeNode<int>* root=new TreeNode<int>(rootData);
q.push(root);
while(q.size()!=0){

TreeNode<int>* front=q.front();
q.pop();
cout<<"Enter no of children for "<<front->data<<endl;
cin>>num;

for(int i=0;i<num;i++){
int data=0;
cout<<"Enter "<<i<<"th data for"<<front->data<<endl;
cin>>data;
TreeNode<int>* root=new TreeNode<int>(data);
q.push(root);
front->children.push_back(root);
}
}
return root;
}


void printLevelWise(TreeNode<int>* root) {
        queue<TreeNode<int>*> q;

    q.push(root);
    while(q.size()!=0){
    TreeNode<int>* root=q.front();
    cout<<root->data<<":";
    int size=root->children.size();
    q.pop();
    for(int i=0;i<size;i++){
        if(i==size-1){
                   cout<<root->children[i]->data;

        }
        else{
       cout<<root->children[i]->data<<",";

        }
        q.push(root->children[i]);
    }
    cout<<endl;
    }

}

void printRecursive(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        printRecursive(root->children[i]);
    }

}
// Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
int getLargeNodeCount(TreeNode<int>* root, int x) {
    int n=0;
    if(root->data>x){
        n++;
    }
    for(int i=0;i<root->children.size();i++){
      n=n+getLargeNodeCount(root->children[i], x);
    }
    return n;
}

void printLevelWise(TreeNode<int>* root){
 queue<TreeNode<int>*> q;
 q.push(root);
 while(q.size()!=0){
    TreeNode<int>* front=q.front();
    cout<<front->data;
    int num=front->children.size();
    for(int i=0;i<num;i++){
cout<<front->children[i]->data;
q.push(front->children[i]);
    }
    q.pop();
 }   
}

void printRecursive1(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;

    int size=root->children.size();
    for(int i=0;i<size;i++){
    printRecursive1(root->children[i]);

    }
}

void printDepthD(TreeNode<int>* root,int d){
if(root==NULL){
    return;
}
if(d==0){
    cout<<root->data<<endl;
    return;
}
for(int i=0;i<root->children.size();i++){
printDepthD(root->children[i],d-1);
}
}

int countLeafNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int n=0;
    if(root->children.size()==0){
        return 1;
    }
  
    for(int i=0;i<root->children.size();i++){
        n=n+countLeafNodes(root->children[i]);
}
return n;
}

void printPostorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printPostorder(root->children[i]);
    }
    cout<<root->data<<endl;
}
bool isPresent(TreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
        if(isPresent(root->children[i],x)){
            return true;
        }
    }
    return false;
}


TreeNode<int>* maxSumNode(TreeNode<int>* root) {


 vector <pair<int,TreeNode<int>*>> v;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode<int>* node=q.front();
        q.pop();
int sum=node->data;
        for(int i=0;i<node->children.size();i++){
            sum=sum+node->children[i]->data;
            q.push(node->children[i]);
        }
        pair<int,TreeNode<int>*> mypair(sum,node);
       v.push_back(mypair); 
    }
    TreeNode<int>* node1=root;
    int max=root->data;


    for(int i=0;i<v.size();i++){
if(v[i].first>max){
    node1=v[i].second;
    max=v[i].first;
}
    }
    return node1;
}
// OR BY RECURSION 

pair<int,TreeNode<int>*> maxSum(TreeNode<int>* root){

    if(root==NULL){
        pair<int,TreeNode<int>*> mypair(0,NULL);
        return mypair;
    }
    int max=root->data;
    for(int i=0;i<root->children.size();i++){
        max=max+root->children[i]->data;
    }
    pair<int,TreeNode<int>*> pair1(max,root);
    for(int i=0;i<root->children.size();i++){
        pair<int,TreeNode<int>*> mypair=maxSum(root->children[i]);
        if(mypair.first!=0){
          if(mypair.first>pair1.first){
            pair1.first=mypair.first;
            pair1.second=mypair.second;
          }
        }
    }
return pair1;

}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
pair<int,TreeNode<int>*> pair=maxSum(root);
return pair.second;
}

// Structurally Identiacal --- by using queue
// nextLargerElemnt than x,-- can be done recursivley,or first storing >x values in

int main(){
    TreeNode<int> *root=inputLevelWise();
    cout<<endl;
    printRecursive(root);

}