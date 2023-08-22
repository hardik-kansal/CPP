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
int main(){
 Node* n1=new Node(10);
 Node*n2=new Node(20);
 Node* n3=new Node(30);
 Node* n4=new Node(40);
 Node*head=n1;
 n1->next=n2;
 n2->next=n3;
 n3->next=n4;
 cout<<head<<endl;
 print(head);
 cout<<head<<endl;
delete n1;
delete n2;
delete n3;
delete n4;

}