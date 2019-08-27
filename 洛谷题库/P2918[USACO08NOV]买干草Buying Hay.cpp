#include<cstdio>
#define min(a,b) (a)<(b)?(a):(b)
int n,m,w[200],c[200],f[60000],ans=1000000000;
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=m+5000;++i)f[i]=1000000000;
    for(int i=1;i<=n;++i)scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;++i)
        for(register int j=w[i];j<=m+5000;++j)
            f[j]=min(f[j],f[j-w[i]]+c[i]);
    for(register int i=m;i<=m+5000;++i)ans=min(ans,f[i]);
    printf("%d",ans);
}
