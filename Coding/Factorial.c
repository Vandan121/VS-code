#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void calculate(char ans[], long count, long n);

int main()
{
char ans[1000000] = {1};
long n;
long count = 1;
scanf("%ld", &n);
calculate(ans, count, n);
return 0;
}

void calculate(char ans[], long count, long n)
{
    long x, prod, carry = 0;
    for(x = 1; x<=n; x++)
    {
        for(long i = 0; i<count; i++)
        {
            prod = ans[i]*x + carry;
            if(prod>9)
            {
                carry = (prod - (prod%10))/10;
                ans[i] = prod % 10;
                if(i == (count-1))
                {
                    count++;
                }
                continue;
            }
            ans[i] = prod;
            carry = 0;
        }
    }
    for(long j = count-1; j>=0; j--)
    {
        printf("%d", ans[j]);
    }
    //printf("\n%ld",count);
}