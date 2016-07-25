#include<stdio.h>

void f(int m, int n);

int main()
{
    f(2, 10000);
    return 0;
}





int main()
{
    int n;
    scanf("%d", &n);
    int i, j=0;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
            j++;
    }
    if(j==2)
        printf("yes");
    else
        printf("no");
    return 0;
}


void f(int begin, int end)
{
    int i;
    for(i=begin; i<=end; i++)
    {
        if(i/2<2)
        {
            if(i==1 || i==0)
                ;
            else
                printf("%d  ", i);
        }
        else
        {
            int j;
            j=2;
            while(j<=i/2)
            {
                if(i%j==0)
                {
                    break;
                }
                else
                {
                    if(j==i/2)
                        printf("%d  ", i);
                    j++;
                }
            }
        }
    }
}




#include<stdio.h>


void find(int begin, int end);

int main()
{
	find(65, 100);
	return 0;
}


void find(int begin, int end)
{
	int i, j;
	if(begin/2<2)
	{
		if(begin!=1  && begin!=0)
			printf("%d  ", begin);
		begin++;
	}
	for(j=begin; j<end; )
	{
loop:	j++;
		for(i=2; i<=j/2; i++)
		{
			if(j%i==0)
				goto loop;
		}
		if(j>end)
			break;
		printf("%d  ", j);

	}
	puts(" ");
}
