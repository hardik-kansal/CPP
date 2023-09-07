#include <iostream>
#include "TrieNode.h"
using namespace std;
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            delete root->children[i];
        }
        delete root;
    }
private:
void insert(TrieNode* root,string word){
    if(root==NULL){
    return;
}
    if(word.length()==0){

root->isTerminal=true;
return;
    }

int index=word[0]-'a';
if(root->children[index]==NULL){
TrieNode* child=new TrieNode(word[0]);
root->children[index]=child;
insert(child,word.substr(1));
}
else{
insert(root->children[index],word.substr(1));
}
}
public:
void insert(string word){
insert(root,word);
}
private:
bool search(TrieNode* root,string word){
if(root==NULL){
    return false;
}
if(word.length()==0){
    return root->isTerminal;
}
int index=word[0]-'a';
if(root->children[index]==NULL){
    return false;
}
return search(root->children[index],word.substr(1));
}
public:
bool search(string word){
cout<<search(root,word)<<endl;
}
};


int main(){
Trie q;
q.insert("bench");
q.insert("bed");
q.insert("hello");
q.insert("world");
q.insert("base");
q.insert("bored");
q.insert("bedtimee");
q.insert("narauto");
q.search("bench");
q.search("bedtime");
}