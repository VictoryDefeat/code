#include <cstdio>
int n,m,w[2001],c[2001],f[2001];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;i++)
        for(int v=m;v>=w[i];v--)
            if(f[v]<f[v-w[i]]+c[i])f[v]=f[v-w[i]]+c[i];
    printf("%d",f[m]);
}
