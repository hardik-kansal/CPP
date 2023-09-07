#include<iostream>
#include "priority_queue.h"
#include <queue> // includes inbuilt priority_queue max type
using namespace std;
int main(){
priority_queue<int> q;
q.push(10);
q.push(20);
cout<<q.top()<<endl;
q.pop();
cout<<q.top()<<endl;
// like arrays,stack,ll,queue
}