#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[20][20][20][20],a[12][12],n,x,y,z;
int maxx(int a,int b,int c,int d)
{
    if(a>=b&&a>=c&&a>=d)return a;
    if(b>=a&&b>=c&&b>=d)return b;
    if(c>=b&&c>=a&&c>=d)return c;
    if(d>=b&&d>=c&&d>=a)return d;
}
int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&z);
    while(x||y||z)
    {
        a[x][y]=z;
        scanf("%d%d%d",&x,&y,&z);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                for(int l=1;l<=n;++l)
                {
                    f[i][j][k][l]=maxx(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
                    if(!(i^k||j^l))f[i][j][k][l]-=a[i][j];
                }
    cout<<f[n][n][n][n];
}
