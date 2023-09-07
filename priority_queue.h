#include <climits>
#include <vector>
using namespace std;
class PriorityQueue {
    vector<int> v;

   public:
   PriorityQueue(){}

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        v.push_back(element);
        int childIndex=v.size()-1;
        int parentIndex=(childIndex-1)/2;

        while(parentIndex>=0){

        if(v[childIndex]>v[parentIndex]){
            int tem=v[parentIndex];
            v[parentIndex]=v[childIndex];
            v[childIndex]=tem;
        }
        else{
break;
        }
childIndex=parentIndex;
parentIndex=(childIndex-1)/2;
        }
    
    }

    int getMax() {
        if(!isEmpty()){
            return v[0];
        }
        return INT_MIN;
    }




    int removeMax() {
        if(isEmpty()){
return INT_MIN;
        }
        int max=v[0];
v[0]=v[getSize()-1];
v.pop_back();
int parentIndex=0;
int leftIndex=1;
int rightIndex=2;
while(leftIndex<v.size()){
int maxIndex=v[leftIndex]>v[rightIndex]?leftIndex:rightIndex;
if(!(maxIndex<v.size())){
    break;
}
if(v[maxIndex]>v[parentIndex]){
int tem=v[parentIndex];
v[parentIndex]=v[maxIndex];
v[maxIndex]=tem;
}
else{
    break;
}
leftIndex=2*parentIndex+1;
rightIndex=2*parentIndex+2;

parentIndex=maxIndex;
}
        return max;
    }

    int getSize() { 
        return v.size();
    }

    bool isEmpty() {
        return v.size()==0;
    }
};