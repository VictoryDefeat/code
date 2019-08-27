#include<cstdio>
long long n,m,w[30],f[20000];
int main()
{
    f[0]=1;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&w[i]);
    for(int i=1;i<=n;++i)
        for(int j=w[i];j<=m;++j)
            f[j]+=f[j-w[i]];
    printf("%lld",f[m]);
}
