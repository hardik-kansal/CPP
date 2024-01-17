#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data){
    this->data=data;
    next=NULL;
}
};


template <typename T>
class QueueUsingArray{
    private:
    int capacity;
    int size;
    int frontIndex;
    int nextIndex;
    T* array;
    public:
    QueueUsingArray(int s){
        size=0;
        capacity=s;
        array=new T[s];
        frontIndex=-1;
        nextIndex=0;
    }
int getSize(){
    return size;
}
bool isEmpty(){
    return size==0;
}
T front(){
    if (isEmpty()){
        cout<<"EMPTY!"<<endl;
        return -1;
    }
    return array[frontIndex];
}
void enqueue(T data){
    if(size==capacity){
        T* newArray=new T[2*capacity];
        int j=0;;
        for(int i=frontIndex;i<capacity;i++){
            newArray[j]=array[i];
            j++;
    }
    for(int i=0 ;i<frontIndex;i++){
        newArray[j]=array[i];
        j++;
    }
    frontIndex=0;
    nextIndex=size;
    capacity=capacity*2;
    array=newArray;
    }
    array[nextIndex]=data;
    size++;
    nextIndex=(nextIndex+1)%capacity;

}
T dequeue(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    size--;
    T fi=array[frontIndex];
    frontIndex=(frontIndex+1)%capacity;
    if(size==0){
        frontIndex=-1;
        nextIndex=0;
    }
    return fi;
}
};


class queueUsingLL{
private:
int size;
Node* head;
Node* tail;
public:

queueUsingLL(){
    head=NULL;
    tail=NULL;
    size=0;
}
bool isEmpty(){
    return size==0;
}
int getSize(){
    return size;
}
int front(){
if(isEmpty()){
    return -1;
}
else{
    return head->data;
}}
void enqueue(int data){
Node* node=new Node(data);
if(isEmpty()){


    this->head=node;
    this->tail=node;
}
else{
    tail->next=node;
    tail=node;
}
    size++;
}
int dequeue(){
    if(isEmpty()){
        return -1;
    }
    int tem=head->data;
    Node* next=head->next;
    delete head;
    head=next;
    size--;
    return tem;
}

};
