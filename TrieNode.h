#include <string>
using namespace std;
class TrieNode{
public:
TrieNode** children;
char data;
bool isTerminal;

TrieNode(char data){
    isTerminal=false;
    this->data=data;
    children=new TrieNode*[26];
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
}
};