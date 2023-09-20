#include <iostream>
#include <climits>
#include <queue>
using namespace std;


int getMin(int* visited,int* distance,int V){
    int minIndex=-1;
    int min=INT_MAX;
    for(int i=0;i<V;i++){
if(visited[i]!=1 && distance[i]<min){
    min=distance[i];
    minIndex=i;
}
 }
return minIndex;
}




void dijkstra(int**matrix,int*distance,int* visited,int V,int sv){
visited[sv]=1;
for(int i=0;i<V;i++){
    if(visited[i]!=1 && matrix[sv][i]>0 && distance[i]>=distance[sv]+matrix[sv][i] ){
    distance[i]=distance[sv]+matrix[sv][i];
    }
}
int a =getMin(visited,distance,V);
if(a==-1){
    return;
}
else{
    dijkstra(matrix, distance, visited, V, a);
}

}

int main() {
    int V,E;
    cin>>V>>E;
    int**matrix=new int*[V];
    for(int i=0;i<V;i++){
        int* arr=new int[V];
        for(int j=0;j<V;j++){
            arr[j]=0;
        }
        matrix[i]=arr;
    }
    for(int i=0;i<E;i++){
        int l,r,d;
        cin>>l>>r>>d;
 matrix[l][r]=d;
 matrix[r][l]=d;
 }
int visited[V];
int distance[V];
for(int i=0;i<V;i++){
    visited[i]=0;
    distance[i]=INT_MAX;
}
distance[0]=0;
dijkstra(matrix,distance,visited,V,0);
cout<<endl;
for(int i=0;i<V;i++){
    cout<<i<<' '<<distance[i]<<endl;
}

for(int i=0;i<V;i++){
    delete[] matrix[i];
}
delete[] matrix;
}
/*
4 4
0 1 3
0 3 5
1 2 1
2 3 8
*/