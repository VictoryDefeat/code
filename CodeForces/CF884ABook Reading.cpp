#include<cstdio>
int n,t,x,sum;
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        sum+=86400-x;
        if(sum>=t)
        {
            printf("%d",i);
            return 0;
        }
    }
}
