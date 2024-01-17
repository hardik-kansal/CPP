// stack.h means cant write main function inside it.
#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class StackUsingArray {
T *data;
int nextIndex;
int capacity;
public :

StackUsingArray() {
data = new T[4];
nextIndex = 0;
capacity = 4;
}

int size() const {
return nextIndex;
}

bool isEmpty() const{
return nextIndex == 0;
}

void push(int element) {
if(nextIndex == capacity) {
int *newData = new T[2 * capacity]; //Capacity doubled
for(int i = 0; i < capacity; i++) {
newData[i] = data[i]; 
}
capacity *= 2;
delete [] data;
data = newData;
}
data[nextIndex] = element;
nextIndex++;
}

T pop() {
if(isEmpty()) {
cout << "Stack is empty " << endl;
return 0;
}
nextIndex--;
return data[nextIndex];
}

int top() {
if(isEmpty()) {
cout << "Stack is empty " << endl;
return INT_MIN;
}
return data[nextIndex - 1];
}
};
template <typename T>
class Node {
        T data;
    	Node<T> *next;
    	public :
    	

    	Node(T data) {
        	this->data = data;
        	next = NULL;
    	}
	};




// Stack Using Linked List
template <typename T>
class Stack {
	Node<T>* head;
    int size;
   public:
    Stack() {
        head=NULL;
        size=0;
    }

    int getSize() {
       return size;
    }

    bool isEmpty() { return size == 0; }

    void push(int element) {
        if(!head){
            Node<T>* newNode=new Node<T>(element);
            head=newNode;
            size++;
        }
        else{
                    Node<T>* newNode=new Node<T>(element);
                    newNode->next=head;
                    head=newNode;
                    size++;
        }

    }

    T pop() {
        if(!isEmpty()){
           T tem= head->data;
           head=head->next;
           size--;
return tem;


        }
        return -1;
    }

    int top() {
       return isEmpty()? -1:head->data;
    }
};

template <typename T>
class vector{

private:
int capacity;
T * array;
int size;
public:
vector(){
    capacity=1;
    array=new T[capacity];
    size=0;
}
bool isEmpty(){
    return (size==0);
}
T top(){
    return isEmpty()?-1:array[size-1];
}
void push_back(T data){
    if(size==capacity){
      T* array1=new T[capacity*2];
      for (int i=0;i<capacity;i++){
        array1[i]=array[i];
      }
      delete []array;
      array=array1;
      capacity=capacity*2;
    }
    array[size]=data;
    size++;
}
T pop(){
    if(isEmpty()){
        return -1;
    }
    else{
        size--;
        T data=array[size];
        return data;
    }
}
};
