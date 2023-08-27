#include <iostream>
#include "queue.h"
using namespace std;
int main(){
    QueueUsingArray<int> q1(3);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    q1.enqueue(40);
    q1.enqueue(40);
    q1.enqueue(40);
    q1.enqueue(40);
    q1.enqueue(40);
    
        cout<<q1.dequeue()<<endl;
        cout<<q1.dequeue()<<endl;
        cout<<q1.dequeue()<<endl;
        cout<<q1.dequeue()<<endl;
        cout<<q1.dequeue()<<endl;
        cout<<q1.dequeue()<<endl;



    
    
    
    
    

}