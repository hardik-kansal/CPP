// EV+Elog(E)
#include <iostream>
#include <algorithm>
using namespace std;

class edge {
public:
    int source;
    int dest;
    int weight;
    edge(){}
    edge(int source, int dest, int weight) {
        this->source = source;
        this->dest = dest;
        this->weight = weight;
    }
};

bool comparef(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

bool outputf(const edge& a, const edge& b) {
    return a.source < b.source;
}

pair<int,int> checkParent(const edge& a, int* parents) {
    int v1 = a.source;
    int v2 = a.dest;
    while (parents[v1] != v1) {
        v1 = parents[v1];
    }
    while (parents[v2] != v2) {
        v2 = parents[v2];
    }
    return pair<int,int>(v1,v2);
}

int main() {
    int V, E;
    cin >> V >> E;

    edge* edges = new edge[E];
    int* parents = new int[V];

    for (int i = 0; i < E; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[i] = edge(v1, v2, w);
    }
for(int i=0;i<V;i++){
            parents[i] = i;

}
    sort(edges, edges + E, comparef);

    int count = 0;
    int i = 0;
    edge* output = new edge[V - 1];

    while (count != V - 1) {
        edge a = edges[i];
pair<int,int> b=checkParent(a, parents);
        if (b.first!=b.second) {
            int v1 = a.source;
            int v2 = a.dest;
            parents[b.first] =b.second;
            output[count] = a;
            count++;
        }

        i++;
    }


cout<<"kruskal--"<<endl;
    for (int i = 0; i < V - 1; i++) {
        edge out = output[i];
        if(out.source<=out.dest){
        cout << out.source << ' ' << out.dest << ' ' << out.weight << endl;
}
else{
            cout << out.dest << ' ' << out.source << ' ' << out.weight << endl;

}
    }

    delete[] edges;
    delete[] parents;
    delete[] output;
}

/*
4 4
1 2 6
2 3 2
1 3 2
1 0 2



*/