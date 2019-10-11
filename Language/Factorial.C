#include<stdio.h>

int main()
{
int i=1,n,fact=1;
clrscr();
printf("\n Enter a number: ");
scanf("%d",&n);
do
{
fact=fact*i;
i++;
}while(i<=n);
printf("\n Factorial: %d",fact);
getch();
return 0;
}