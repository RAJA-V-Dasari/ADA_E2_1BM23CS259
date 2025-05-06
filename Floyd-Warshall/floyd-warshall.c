#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 100
int min(int a, int b){
    int m = a>b?b:a;
    return m;
}
void floyd_warshall(int graph[SIZE][SIZE],int n){
    int D[n][n];
    for(int i = 0 ; i<n;i++){
        for(int j = 0; j<n ;j++){
            D[i][j] = graph[i][j];
        }
    }

    for(int k = 0;k<n;k++){
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<n ;j++){
                if(D[i][k]!= INT_MAX && D[k][j]!=INT_MAX){
                    D[i][j]= min(D[i][j], D[i][k]+D[k][j]);
                }
            }
        }
    }
    printf("The final matrix D is:\n");
    for(int i = 0 ; i<n;i++){
        for(int j = 0; j<n ;j++){
            if(D[i][j]!=INT_MAX)printf("%d ",D[i][j]);
            else printf("INF ");
        }
        printf("\n");
    }
    for(int i = 0 ; i<n;i++){
        for(int j = 0; j<n ;j++){
            if(D[i][j]!=0 && D[i][j]!=INT_MAX){
                printf("Shortest Path from %d to %d : %d\n", i,j,D[i][j]);
            }
        }
    }
}

int main(){
    int n;
    int graph[SIZE][SIZE];

    printf("Enter number of vertices :");
    scanf("%d",&n);
    printf("For no direct edge enter -1\n");
    for(int i =0;i<n;i++){
        for(int j =0; j<n;j++) scanf("%d",&graph[i][j]);
    }

    for(int i =0;i<n;i++){
        for(int j =0; j<n;j++){
            if(graph[i][j]==-1) graph[i][j]=INT_MAX;
        }
    }
    floyd_warshall(graph,n);
    return 0;
}
