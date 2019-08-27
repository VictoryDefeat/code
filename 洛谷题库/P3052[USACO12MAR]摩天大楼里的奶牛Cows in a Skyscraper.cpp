#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,w[20],ans,dp[20][500000],high;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&w[i]);
    for(int i=1;i<=n;++i)
        for(int j=0;j<=(1<<n)-1;++j)
            dp[i][j]=1<<30;
    for(int i=1;i<=n;++i)dp[1][(1<<(i-1))-1]=w[i];
    for(int i=1;i<=n+1;++i)
        for(int j=0;j<=(1<<n)-1;++j)
            if(dp[i][j]!=1<<30)
                for(int k=1;k<=n;++k)
                {
                    if(j&(1<<k))continue;
                    if(dp[i][j]+w[k]<=m)
                        dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i][j]+w[k]);
                    else
                        dp[i+1][j|(1<<k)]=min(dp[i][j|(1<<k)],w[k]);
                }
    for(int i=1;i<=n+1;++i)
        if(dp[i][(1<<n)-1]!=1<<30)
        {
            printf("%d",i-1);
            break;
        }
}
