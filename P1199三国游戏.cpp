#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
const int N=1010;
int n,a[N][N],ans;
int main(int argc,char ** argv)
{
    scanf("%d",&n);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    for(int i=1;i<=n;++i)
    {
        sort(a[i]+1,a[i]+1+n);
        ans=max(ans,a[i][n-1]);
    }
    printf("1\n%d",ans);
	return 0;
}