#include <stdio.h>

#include<stdlib.h>

#include<string.h>

int main() {

    int n,arg,num=0,temp,sum=0,l,r,flag=1;
    char name[1000000];
    scanf("%d",&n);

    switch(n)
    {
        case 1: //given n elements, sum 
            arg,num=0,temp,sum=0;
            scanf("%d%d",&arg,&sum);
            for(int i=0;i<=arg;i++){
                int a = scanf("%d",&temp);
                if(a != -1){
                    sum -= temp;
                    num += 1;
                } 
            }
            if(num != arg || sum != 0){
                printf("Testcase is Invalid!\n");
            }
            else{
                printf("Testcase is valid!\n");
            }
        break;
        case 2: // string with length n
            scanf("%d",&arg);
            fgets(name, sizeof(name), stdin);  // read string
            n=0;
            for(int i=0;i<1000000;i++){
                if(name[i] == '\n') break;
                n++;
            }
            if(n != arg){
                printf("Testcase is Invalid!\n");
            }
            else{
                printf("Testcase is valid!\n");
            }
            break;
        case 3: // numbers in a given range
            scanf("%d",&arg);
            scanf("%d%d",&l,&r);
            for(int i=0;i<=arg && flag;i++){
                int a = scanf("%d",&temp);
                if(a != -1){
                    if(temp < l || temp > r){
                        flag=0;
                        break;
                    }
                    num += 1;
                } 
            }
            if(num != arg || !flag){
                printf("Testcase is Invalid!\n");
            }
            else{
                printf("Testcase is valid!\n");
            }
            break;
    }
   return 0;

}