#include <iostream>
#include <queue>
using namespace std;
void printBFS(int* visited,int E,int V,int** matrix){
for(int sv=0;sv<V;sv++){
if(visited[sv]!=1){
queue<int> q;
q.push(sv);
visited[sv]=1;
while(q.size()!=0){
int front=q.front();
cout<<front<<' ';
q.pop();
for(int i=0;i<V;i++){
    if(i==front){
        continue;
    }
    if(matrix[front][i]==1 && visited[i]!=1){
        q.push(i);
        visited[i]=1;
    }}}
    }
}    
}

void printDFS(int* visited,int sv,int V,int** matrix){
cout<<sv<<' ';
visited[sv]=1;
for(int j=0;j<V;j++){
    if(visited[j]!=1){
printDFS(visited,j,V,matrix);

    }
}

}






int main() {
 int V,E;
 cin>>V>>E;
 int** matrix=new int*[V];
 for(int i=0;i<V;i++){
     int* arr=new int[V];
     for(int j=0;j<V;j++){
         arr[j]=0;
     }
     matrix[i]=arr;
 }
 for(int i=0;i<E;i++){
 int l=0,r=0;
cin>>l>>r;
matrix[l-1][r-1]=1;
matrix[r-1][l-1]=1;
}
int* visited=new int[V];
for(int i=0;i<V;i++){
    visited[i]=0;
}
printBFS(visited,E,V,matrix);
cout<<endl;
for(int i=0;i<V;i++){
    visited[i]=0;
}
printDFS(visited,0,V,matrix);
for(int i=0;i<V;i++){
    delete[] matrix[i];

}
delete[] matrix;
delete[] visited;
}