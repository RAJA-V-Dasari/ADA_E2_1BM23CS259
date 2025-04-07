#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[b] = a;
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edgeCount = 0, minCost = 0;

    printf("Edge \tWeight\n");

    while (edgeCount < V - 1) {
        int min = 99999, a = -1, b = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != 0 && graph[i][j] < min && find(i) != find(j)) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            unionSet(a, b);
            printf("%d - %d \t%d\n", a, b, min);
            minCost += min;
            edgeCount++;
        } else {
            break;
        }
    }

    printf("Total weight of MST: %d\n", minCost);

    return 0;
}
