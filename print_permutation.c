#include <stdio.h>

void print_permutation(int n,int* A,int cur){
    int i,j;
    if(cur == n){
            for(i=0;i<n;i++){
                printf("%d",A[i]);
            }

    }else{
        for(i=0;i<n;i++){
                for(j=0;j<cur;j++){
                if(A[j] != i){
                    A[cur]=i;
                }

            }
             print_permutation(n,A,cur++);

            }

    }
}
 int main(){
     int A[10];
     print_permutation(4,A,0);


 }
