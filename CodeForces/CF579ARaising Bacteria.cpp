#include<cstdio>
int n,sum;
int main()
{
    scanf("%d",&n);
    while(n)
    {
        sum+=n&1;
        n>>=1;
    }
    printf("%d",sum);
}
