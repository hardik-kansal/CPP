#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


// return string with unique character in same order.
string uniqueChar(string str) {
	string s1="";
	unordered_map<char,int> ourmap;
for(int i=0;i<str.length();i++){
	ourmap[str[i]]++;
}
for (int i = 0; i < str.length(); i++) {
if(ourmap.count(str[i])>0){
s1=s1+str[i];
ourmap.erase(str[i]);
}
}
return s1;
}




int main(){
    unordered_map<string,int> map;
    map["a"]=1;
    map["b"]=2;
    map["c"]=3;
    map["d"]=4;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
vector<int>::iterator it=v.begin();
while(it!=v.end()){
cout<<*it<<endl;
it++;
}
unordered_map<string,int>::iterator it2=map.find("b"); // find returns an iterator
while(it2!=map.end()){
    cout<<it2->first<<endl;
    it2++;

    // map.erase(it2,it2+4); -- starting and ending iterator.
    // if we first erase it,then use it--gives segmentation fault.
    // .begin(),.end() are too iterators.

}
}