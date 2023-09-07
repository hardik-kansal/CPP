#include <iostream>
#include "hashmap.h"
using namespace std;
int main(){
    ourmap<int> map;
    cout<<map.getSize()<<endl;

    for(int i=0; i<10; i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        map.insert(key,i+1);
        cout<<map.getLoadFactor()<<endl;
    }
    cout<<map.getSize()<<endl;




    
    map.remove("abc0");
    map.remove("abc7");
       for(int i=0; i<10; i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<"key: "<<key<<" value: "<<map.findit(key)<<endl;
    }

    cout<<map.getSize()<<endl;


}