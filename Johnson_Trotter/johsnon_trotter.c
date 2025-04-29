#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_perm(int p[],int n){
    printf("Permutation: ");
    for(int i = 0;i<n; i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}
void johnson_trotter(int n){
    int p[n];
    int d[n];
    for(int i = 0;i<n;i++){
        p[i] = i+1;
        d[i] = -1;
    }
    print_perm(p,n);

    while(1){
        int largest_mob = -1;
        int largest_ind = -1;

        for(int i=0; i<n;i++){
            if(d[i] == -1 && i>0 && p[i]>p[i-1]){
                if(p[i]>largest_mob){
                    largest_mob = p[i];
                    largest_ind = i;
                }
            }
            else if(d[i] == 1 && i<n-1 && p[i]>p[i+1]){
                if(p[i]>largest_mob){
                    largest_mob = p[i];
                    largest_ind = i;
                }
            }
        }
        if(largest_mob == -1) break;
        int ind = largest_ind;
         if(d[ind]==-1){
            swap(&p[ind],&p[ind-1]);
            swap(&d[ind],&d[ind-1]);
        }
        else if(d[ind]==1){
            swap(&p[ind],&p[ind+1]);
            swap(&d[ind],&d[ind+1]);
        }
        for(int j = 0;j<n;j++){
            if(p[j]>largest_mob){
                d[j]= d[j]*-1;
            }
        }
      print_perm(p,n);
    }
}

int main(){
    int n;
    printf("Enter number of elements to be permuted: ");
    scanf("%d",&n);
    johnson_trotter(n);
}
