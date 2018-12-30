#include <stdio.h>
#include <stdlib.h>


void print_permutation(int n,int* A,int cur){
    int i,j;
    if(cur == n){
            for(i=0;i<n;i++){
                printf("%d\t",A[i]);

            }
            printf("\n");

    }else{
        for(i=0;i<n;i++){
                int repeat = 0;
                for(j=0;j<cur;j++){
                if(A[j] == i){
                    repeat = 1;
                    break;
                }

            }
            if (repeat == 0){
                A[cur] = i;
                cur++;
                print_permutation(n,A,cur);
                cur--;//ATTENTION!!!!WRONG AGAIN!
            }




            }

    }
}
 int main(){
     int A[10];
     print_permutation(4,A,0);


 }
