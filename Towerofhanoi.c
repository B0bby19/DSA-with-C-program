//Tower of Hanoi
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

void TOH(int,char,char,char);

int main()
{
    int n;
    printf("Enter the number of disk\n");
    scanf("%d",&n);
    TOH(n,'O','D','I');
    getch();
}

void TOH(int n,char A,char B, char C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,B);
        TOH(n-1,C,B,A);
    }
}




