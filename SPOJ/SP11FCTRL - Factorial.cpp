#include<cstdio>
int t,n,sum;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        while(n)
            sum+=n/=5;
        printf("%d\n",sum);
    }
}
