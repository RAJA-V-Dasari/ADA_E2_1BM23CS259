#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100

int findMin(int dist[], int visited[], int V){
    int min = INT_MAX;
    int min_ind;
    for(int i=0; i<V;i++ ){
        if(visited[i]==0 &&  dist[i]<min){
            min = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void printPath(int prev[], int j) {
    if (prev[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(prev, prev[j]);
    printf("-> %d ", j);
}

void djikstra(int graph[MAX][MAX],int src,int V){
    int dist[V];
    int visited[V];
    int prev[V];

    for(int i = 0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
        prev[i] = -1;
    }

    dist[src] = 0;

    for(int j = 0; j< V-1; j++){
        int u = findMin(dist, visited, V);
        visited[u] = 1;

        for(int v = 0; v<V ; v++){
            if(visited[v] == 0 && graph[u][v]!=0 && dist[u]!=INT_MAX){
                if(dist[u]+graph[u][v] < dist[v]){
                    dist[v] = dist[u]+graph[u][v];
                    prev[v] = u;
                }
            }
        }

    }

    printf("Vertex \t Shortest Distance\n");
    for(int i = 0; i<V;i++){
        printf("%d \t %d\t\t",i,dist[i]);
        printf("Shortest Path: ");
        printPath(prev, i);
        printf("\n");
    }

}

int main(){
    int V;
    int graph[MAX][MAX];
    int src;
    printf("Number of vertices: ");
    scanf("%d",&V);

    printf("Enter Weighted Adjacency Matrix ( 0 if no edge ):\n");
    for(int i = 0;i<V;i++){
        for(int j = 0; j<V; j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("\nSource Vertex: ");
    scanf("%d",&src);

    djikstra(graph,src,V);

    return 0;

}
