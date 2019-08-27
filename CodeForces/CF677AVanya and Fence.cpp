#include<cstdio>
int n,k,x,sum;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>k)sum+=2;
        else sum++;
    }
    printf("%d",sum);
}
