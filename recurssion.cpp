#include <iostream>
using namespace std;
// Given an array of length N and an integer x, you need to find 
// and return the last index of integer x present in the array.
//  Return -1 if it is not present in the array.
int lastIndex(int input[], int size, int x) {
if(size==0){
  return -1;
}
int ans=lastIndex(input+1, size-1, x);
if(ans==-1){
  if(input[0]==x){
    return 0;
  }
  return -1;
}
return ans+1;
}

int main(){

}