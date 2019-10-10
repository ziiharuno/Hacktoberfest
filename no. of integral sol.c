#include <stdio.h>

int main()
{
    int i,testcs;
    int eqn[100],num[100];
    printf("Enter the test-cases you want: ");
    scanf("%d",&testcs);
    for(i=0;i<testcs;i++)
    {
        printf("For Equation %d, Enter no.of variables: ",i+1);
        scanf("%d",&eqn[i]);
        printf("Enter number for which solutions are required: ");
        scanf("%d",&num[i]);
    }
    int j,fac1[100],fac2[100],fac3[100],ans[100];
    for(i=0;i<testcs;i++)
    {
        fac1[i]=1;
        fac2[i]=1;
        fac3[i]=1;
        for(j=1;j<=(num[i] - 1);j++)
            fac1[i] = fac1[i] * j;
        for(j=1;j<=(eqn[i] - 1);j++)
            fac2[i] = fac2[i] * j;
        for(j=1;j<=(num[i] - eqn[i]);j++)
            fac3[i] = fac3[i] * j;
        printf("\n No. of integral solutions of equation ");
        for(j=0;j<eqn[i];j++)
        {
            if(j == (eqn[i]-1))
                printf("%c = ",(j+97));
            else
                printf("%c + ",(j+97));
        }
        printf("%d are ",num[i]);
        ans[i] = fac1[i] / (fac2[i] * fac3[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}


