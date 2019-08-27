#include<cstdio>
#include<algorithm>
using namespace std;
int f[200][200],n,m,a[200],sum[200];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;
    a[++n]=m+1;
    sort(a,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=a[i]-a[i-1]-1+sum[i-1];
    for(int l=2;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            for(int p=i;p<j;p++)
                if(!f[i][j]||f[i][j]>f[i][p]+f[p+1][j]+sum[j]-sum[i-1]+j-i-1)
                    f[i][j]=f[i][p]+f[p+1][j]+sum[j]-sum[i-1]+j-i-1;
        }
    printf("%d",f[1][n]);
}
