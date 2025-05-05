#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    int m = a>b?a:b;
    return m;
}

void knapsack(int v[], int w[], int n, int W){
    int dp[n+1][W+1];
    for(int i = 0;i<=n; i++){
        for(int j = 0; j<=W; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=W; j++){
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("Maximum value: %d\n", dp[n][W]);

    printf("Selected item: ");
    int res = dp[n][W];
    int j = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i-1][j]) {
            printf("%d ", i-1);
            res -= v[i-1];
            j -= w[i-1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;
    int values[100], weights[100];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    knapsack(values, weights, n, W);

    return 0;
}


