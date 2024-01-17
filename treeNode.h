#include <vector>
using namespace std;
template <typename T>
class TreeNode {
public:
T data; 
vector<TreeNode<T>*> children; 
TreeNode(T data) { 
this->data = data;
}
~TreeNode(){
    for(int i=0;i<this->children.size();i++){
        delete this->children[i];
    }
    // delete this;
    // above is not req as it gets deleted once destructor called when it goes out of scope.
}
};