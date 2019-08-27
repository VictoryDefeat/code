#include<cstdio>
int t[2000],g[2000],s,n,m;
long long f[10][2000][100];
void dp(int h,int ss,int i)
{
    if(i>=n)
    {
        t[++s]=h;
        g[s]=ss;
        return;
    }
    dp(h,ss,i+1);
    dp(h+(1<<i),ss+1,i+2);
}
int main()
{
    scanf("%d%d",&n,&m);
    dp(0,0,0);
    for(int i=1;i<=s;i++)f[1][i][g[i]]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=s;j++)
            for(int k=1;k<=s;k++)
            {
                if(t[j]&t[k])continue;
                if((t[j]<<1)&t[k])continue;
                if(t[j]&(t[k]<<1))continue;
                for(int z=m;z>=g[j];z--)f[i][j][z]+=f[i-1][k][z-g[j]];
            }
    long long ans=0;
    for(int i=1;i<=s;i++)ans+=f[n][i][m];
    printf("%lld",ans);
}
