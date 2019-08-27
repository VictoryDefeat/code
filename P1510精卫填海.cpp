#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
int n,m,v,w[20000],c[20000],f[20000000];
int main()
{
    scanf("%d%d%d",&v,&n,&m);
    if(m<=0)
    {
        printf("Impossible");
        return 0;
    }
    for(int i=1;i<=n;++i)scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;++i)
        for(int j=m;j>=w[i];--j)
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    for(int i=1;i<=m;++i)
        if(f[i]>=v)
        {
            printf("%d",m-i);
            return 0;
        }
    printf("Impossible");
}
