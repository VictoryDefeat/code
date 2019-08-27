#include<cstdio>
#include<cstdlib>
int f[6000][6000],f1[20000],n,m,x,y,z;
bool visit[20000];
inline bool check()
{
	bool ok=0;
	for(register int i=1;i<=n;++i)
		if(!visit[i])
			ok=1;
	return ok;
}
inline void prim()
{
	int ans=0;
	while(check())
	{
		int minn=1<<30,to=0;
		for(int i=1;i<=n;++i)
			if(!visit[i]&&f1[i]<minn)
			{
				minn=f1[i];
				to=i;
			}
		ans+=f1[to];
		for(int i=1;i<=n;++i)
            if(f1[i]>f[to][i]&&!visit[i])
                f1[i]=f[to][i];
        visit[to]=1;
	}
	printf("%d",ans);
    system("pause");
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=1<<30;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(f[x][y]>z)f[y][x]=f[x][y]=z;
	}
	for(int i=1;i<=n;++i)f1[i]=f[1][i];
	visit[1]=1;
	prim();
}
