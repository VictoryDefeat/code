#include<cstdio>
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
int n,a[30],f[2][2000][2000],sum;
int main()
{
	scanf("%d",&n);
	f[0][0][0]=1;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		for(int j=0;j<2000;++j)
          	for(int k=0;k<2000;++k)
                if(f[i%2][j][k])
                {
                    f[(i+1)%2][j][k]=1;
                    f[(i+1)%2][j+a[i]][k]=1;
                    f[(i+1)%2][j][k+a[i]]=1;
          		}
	}
	if(n==3){printf("%d",max(a[1],max(a[2],a[0])));return 0;}
	int ans=2000;
	for(int i=0;i<2000;++i)
   		for(int j=0;j<2000;++j)
   			if(f[n%2][i][j])
   				ans=min(ans,max(i,max(j,sum-i-j)));
   	printf("%d",ans);
}
