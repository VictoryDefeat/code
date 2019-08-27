#include<cstdio>
long long x,y,n,m,a[30][30],f[30][30];
void z(long long x,long long y)
{
    f[x][y]=1;
    f[x-1][y-2]=1;
    f[x-2][y-1]=1;
    f[x-2][y+1]=1;
    f[x-1][y+2]=1;
    f[x+1][y-2]=1;
    f[x+2][y-1]=1;
    f[x+2][y+1]=1;
    f[x+1][y+2]=1;
}
void work()
{
    a[1][0]=1;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++)
        	if(f[i-1][j-1]) a[i][j]=0;
            else a[i][j]=a[i-1][j]+a[i][j-1];
    printf("%lld",a[n+1][m+1]);
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    z(x,y);
    work();
}
