#include<cstdio>
int n;
double f[2000][2000];
int main()
{
	scanf("%d",&n);n>>=1;
	for(int i=2;i<=n;++i)f[i][0]=1,f[0][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=f[i-1][j]*0.5+f[i][j-1]*0.5;
	printf("%.4lf",f[n][n]);
}
