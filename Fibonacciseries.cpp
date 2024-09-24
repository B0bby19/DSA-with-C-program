//fibonacci series
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int n,i;
    int fibo(int);
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Fibonacci numbers up to %d terms:\n",n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",fibo(i));
    }
    getch();
}

int fibo(int k){
    if(k==0){
        return 0;
    }
    else if(k==1){
    	return 1;
	}
    else {
        return fibo(k-1)+fibo(k-2);
    }
}


