#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *  next;
    Node(int data){
        this->data=data;
        next=NULL;
}
};



void print(Node* n1){  // creates a new copy of n1 pointer which points to original node1
    while(n1!=NULL){
        cout<<n1->data<<endl;
        n1=n1->next;   //Copied pointer value is being changed
    }
}
// PRINT Ith NODE ELEMENT--if i>length or list not exist --print nothing



void printIthNode(Node *head, int i)
{
    int c=0;
	Node* tem=head;
    while(c<i && tem->next !=NULL){
tem=tem->next;
c++;
	}
	if(c==i && tem){
		cout<<tem->data<<endl;
}}





Node* enterdata(){
int data;
cin>>data;
Node* head=NULL;
Node* tail=NULL;
while(data!=-1){
    Node*node=new Node(data);
    if(head==NULL){
        head=node;
        tail=node;
}
else{
    tail->next=node;
    tail=node;
}
cout<<"enter data"<<endl;
cin>>data;
}
return head;
}




Node* insertNode(Node* head,int i,int data){
    int c=0;
    Node* tem=head;
    if(i==0){
        Node* node=new Node(data);
        node->next=tem;
return tem;
    }
    while(c<i-1 && tem){
tem=tem->next;
c++;
    }
    if(tem){
    Node* node=new Node(data);
    node->next=tem->next;
    tem->next=node;
    }return head;
}




int main(){
Node* head=enterdata();
print(head);
cout<<endl;
printIthNode(head,2);
cout<<endl;
insertNode(head,1,100);
print(head);
cout<<endl;
}