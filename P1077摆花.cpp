#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
const int N=110;
const int mod=1000007;
int n,m,a,f[N][N];
int main(int argc,char ** argv)
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i)f[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=0;j<=a;++j)
            for(int k=0;k<=m-j;++k)
            {
                if(j==0&&k==0)continue;
                f[i][j+k]+=f[i-1][k];
                f[i][j+k]%=mod;
            }
    }
    printf("%d\n",f[n][m]%mod);
    return 0;
}