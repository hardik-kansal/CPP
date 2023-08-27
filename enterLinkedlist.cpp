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



Node *appendLastNToFirst(Node *head, int n)
{if(n==0){
	return head;
}
	  Node * tem=head;
if(tem==NULL){
	return head;
}	  
int T=0;
    while(tem->next!=NULL){
tem=tem->next;
T++;
	}
int c=0;
Node*tem2=head;
while(c!=T-n){
	tem2=tem2->next;
	c++;
}
Node* newHead=tem2->next;
tem2->next=NULL;
tem->next=head;	
	return newHead;
}



Node *removeDuplicates(Node *head)   // Consecutive duplicates
{
if(head==NULL){
	return head;
}
    Node * tem1=head;
	Node*tem2=head->next;
	while (tem2) {
	  if(tem1->data==tem2->data){
		  tem1->next=tem2->next;
	
	  }
	  else{
		  	  tem1=tem2;
	  }
	  
      tem2=tem2->next;
	  
	}
	return head;
}



void printReverse(Node *head)
{if(head){
		 Node* tem=head;
int c=1;
while(tem->next!=NULL){
	tem=tem->next;
	c++;
}
 int arr[c];
 Node* tem2=head;
 int i=0;
    while(tem2!=NULL){
		arr[i]=tem2->data;
		tem2=tem2->next;
		i++;
		}
for(int i=c-1;i>-1;i--){
	cout<<arr[i]<<" ";
}	
}
}




bool isPalindrome(Node *head)
{
	if(!head){
		return true;
	}
	if(head->next==NULL){
		return true;
	}
    int c=1;
	Node * tem=head;
	while(tem->next=NULL)
{
	tem=tem->next;
	c++;
}
int arr[c/2];
Node* tem2=head;
bool check=true;
if(c%2==0){
	check=false;
}
for(int i=0;i<c;i++){
if(i<c/2){
	arr[i]=tem2->data;
}
else{
	
	if(check && i==c/2  ){
	tem2=tem2->next;
   continue;
	}
	if(arr[c-i-1]!=tem2->data){
	return false;
	}
}
tem2=tem2->next;
	}	


return true;


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



// Singly Linked list
// Variations--Doubly,circular,doubly-circular