#include<stdio.h>

int main()
{
    int a[3][4]= {1,2,3,45,6,4,5,7,8,9,11,12};
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    int max=a[0][0];
    for(i=0; i<3; i++)
    {
        for(j=1; j<4; j++)
        {
            if(a[i][j]>max)
                max=a[i][j];
        }
    }
    printf("%d", max);
    printf("\n");
    return 0;
}
