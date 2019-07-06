#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_permutation(int n,int* A,int cur){
    int i,j;
    if(cur == n){
            for(i=0;i<n;i++){
                printf("%d\t",A[i]);

            }
            printf("\n");

    }
	else{
        for(i=0;i<n;i++){//i从0到n，试探当前cur位置可不可以等于i，可以，递归cur+1，否则跳过此轮循环
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
    }//else
}
void str_period(char* s){
    int len;
    len = strlen(s);
    printf("len in func is %d\n",len);
for(int i=1;i<=len;i++){
    if(len%i == 0){
        int ok = 1;
        for(int j=i;j<len;j++){
            if(s[j]!=s[j%i]){
                ok = 0;
                break;

            }
        }
        if(ok){
            printf("%d",i);
            break;
        }
    }

}
}
 int main(){
     int A[10];
     //print_permutation(4,A,0);
     //char s[100]= {'q','q',"q","q","q",'3'};//"sssssss";
     //char* s = "jjjjjjjj";
     //char* s = "hiahiahia";
     char* s = "hiahiahii";
     printf("%d\n",strlen(s));
     str_period(s);


 }
