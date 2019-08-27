#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
int f[6000][6000],f1[6000],n,m,x,y,z;
bool visit[6000];
void prim()
{
	int s=0,ans=0;
	while(s<n)
	{
		int minn=1<<30,to=0;
		s++;
		for(int i=1;i<=n;i++)
			if(!visit[i]&&f1[i]<minn)
			{
				minn=f1[i];
				to=i;
			}
		if(minn!=1<<30)ans=max(ans,minn);
		for(int i=1;i<=n;i++)
            if(f1[i]>f[to][i]&&!visit[i])
                f1[i]=f[to][i];
        visit[to]=1;
	}
	printf("%d",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1<<30;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(f[x][y]>z)f[y][x]=f[x][y]=z;
	}
	for(int i=1;i<=n;i++)f1[i]=f[1][i];
	visit[1]=1;
	prim();
}
