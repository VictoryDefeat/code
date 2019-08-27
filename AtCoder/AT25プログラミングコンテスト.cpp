#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
int n,m,x,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        int sum=0;
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&x);
            sum+=x;
        }
        ans=max(sum,ans);
    }
    printf("%d\n",ans);
}
