#include <string>
using namespace std;

template <typename T>
class mapnode{
public:
string key;
T value;
mapnode<T>* next;
mapnode(string key, T value){
this->key=key;
this->value=value;
next=NULL;
}
~mapnode(){
    delete next;
}

};
template <typename T>
class ourmap{
int count;
int bucketSize;
mapnode<T>** bucket;
public:
ourmap(){
    count=0;
    bucketSize=5;
    bucket=new mapnode<T>*[bucketSize];
    for(int i=0;i<bucketSize;i++){
        bucket[i]=NULL;
    }
}
~ourmap(){
    for(int i=0; i<bucketSize;i++){
        delete bucket[i];
    }
    delete [] bucket;
}

T remove(string key){
int index=getIndex(key);
mapnode<T>* head=bucket[index];
mapnode<T>* tem=NULL;
while(head!=NULL){
    if(head->key==key){
        if(tem==NULL){
bucket[index]=head->next;
        }
        else{
        tem->next=head->next;

        }
        head->next=NULL;
        int value=head->value;
        count--;
        delete head;
        return value;
    }
    tem=head;
    head=head->next;
}
return 0;
}
private:
int getIndex(string key){
int sum=0; 
int p=1;   
for(int i=key.size()-1;i>=0;i--){
sum+=key[i]*p;
sum=sum%bucketSize; // storage efficient --simple modulur maths !
p*=37;
p=p%bucketSize;  
}
return sum%bucketSize;
}



public:


void rehash(){
mapnode<T>** tem=bucket;
bucket=new mapnode<T>*[2*bucketSize];
bucketSize*=2;
count=0;
for(int i=0;i<bucketSize;i++){
    bucket[i]=NULL;
}
for(int i=0;i<(bucketSize/2);i++){
mapnode<T>* head=tem[i];    
while(head!=NULL){
string key=head->key;
int value=head->value;
insert(key,value);
head=head->next;
}
}
for(int i=0;i<bucketSize/2;i++){
delete tem[i];
}
delete []tem;
}


void insert(string key,T value){
int index=getIndex(key);
mapnode<T>* head=bucket[index];
if(head!=NULL){
    if(head->key==key){
        head->value=value;
        return;
    }
    head=head->next;
}
mapnode<T>* node=new mapnode<T>(key,value);
node->next=bucket[index];
bucket[index]=node;
count++;
double loadFactor=getLoadFactor();
if(loadFactor>0.7){
    rehash();
}
}

double getLoadFactor(){
    return (1.0)*count/bucketSize;
}
int getSize(){
    return count;
}



T findit(string key){
    int index=getIndex(key);
    mapnode<T>* head=bucket[index];
    while(head!=NULL){
        if(head->key==key){
            return head->value;
        }
head=head->next;

    }
    return 0;

}

};






