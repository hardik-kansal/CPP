#include <iostream>
#include <climits>
using namespace std;



int getMin(int* weight,int V,int* visited){
    int minIndex=-1;
    int min=INT_MAX;
    for(int i=0;i<V;i++){
if(visited[i]!=1 && weight[i]<min){
    min=weight[i];
    minIndex=i;
}
 }
return minIndex;
}




void prim(int** matrix,int*weight,int*parent,int* visited,int  V,int sv){
int count=0;    
if(visited[sv]==1){
    return;
}
visited[sv]=1;
count++;
for(int i=0;i<V;i++){
    if(i==sv){continue;}
else{
    if(matrix[sv][i]>0 && visited[i]!=1){
        if(weight[i]>matrix[sv][i]){
weight[i]=matrix[sv][i];
parent[i]=sv;
        
} }
}
}
int a=getMin(weight,V,visited);
if(a==-1){
    return;
}
else{
prim(matrix, weight, parent, visited,V,a);

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
        int l,r,w;
        cin>>l>>r>>w;
 matrix[l][r]=w;
 matrix[r][l]=w;
 }
int visited[V];
int weight[V];
int parent[V];
for(int i=0;i<V;i++){
    visited[i]=0;
    weight[i]=INT_MAX;
    parent[i]=i;
}
parent[0]=-1;
weight[0]=0;
prim(matrix,weight,parent,visited,V,0);
cout<<endl<<endl;
for(int i=1;i<V;i++){
    int v1=i;
    int v2=parent[i];
    if(v1<v2){
        cout<<v1<<' '<<v2<<' '<<matrix[v1][v2]<<endl;
    }
    else{
                cout<<v2<<' '<<v1<<' '<<matrix[v1][v2]<<endl;

    }
}
for(int i=0;i<V;i++){
    delete[] matrix[i];
}
delete[] matrix;
}
/*
4 4
1 2 6
2 3 2
1 3 2
1 0 2
*/