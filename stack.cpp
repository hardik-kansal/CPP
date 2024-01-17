#include<iostream>
#include "stack.h"
#include <stack>
// exactly same--except pop() doesnt return anything.
using namespace std;
int main(){
stack<char > s1;
s1.push('a');
s1.pop();
cout <<s1.empty();
}
