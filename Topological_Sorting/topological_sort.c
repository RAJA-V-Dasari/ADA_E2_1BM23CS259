#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void topological_sort(int graph[SIZE][SIZE],int n){
    int indegree[n];
    for(int i = 0; i<n; i++) indegree[i]=0;

    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            if(graph[i][j]==1){
                indegree[j]++;
            }
        }
    }

    int source[n];
    int front = 0;
    int last = 0;

    for(int i = 0; i<n; i++){
        if(indegree[i]==0) source[last++]=i;
    }

    int sorted[n];
    int ind = 0;
    while(front<last){
        int temp = source[front++];
        sorted[ind++]= temp;
        for(int i = 0; i<n; i++){
            if(graph[temp][i]==1){
                indegree[i]--;
                if(indegree[i]==0)source[last++]=i;
            }
        }
    }

    if(ind == n){
        printf("Topological Sorted Order is :");
        for(int i = 0; i<n;i++){
          printf(" %d ",sorted[i]);
        }
        printf("\n");
    }
    else{
        printf("Topological Sorting not possible.\n");
    }

}

int main(){
    int graph[SIZE][SIZE];
    int n;

    printf("Enter Number of Vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matric:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    topological_sort(graph,n);
    return 0;
}
