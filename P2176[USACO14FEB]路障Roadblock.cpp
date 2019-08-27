#include<cstdio>
#include<queue>
#define inf 2147483647
using namespace std;
struct Edge
{
	int next,to,dis;
}edge[10000];
bool f[10000];
int ans,a[10000],head[10000],num,n,m,z[10000],x[10000],c[10000],len;
void ins(int p,int q,int v)
{
	edge[++num].next=head[p];
	edge[num].to=q;
	edge[num].dis=v;
	head[p]=num;
}
void spfa(int s)
{
  	queue<int>q;
  	for(int i=1;i<=n;i++)
  	{
  		a[i]=inf;
  		f[i]=0;
	}
	a[s]=0;
	f[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=head[t];i;i=edge[i].next)
		{
			int u=edge[i].to;
			if(a[u]>a[t]+edge[i].dis)
			{
                z[u]=i;x[u]=t;
				a[u]=a[t]+edge[i].dis;
				if(!f[u])
				{
					f[u]=1;
					q.push(u);
                    
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int p,q,v;
		scanf("%d%d%d",&p,&q,&v);
		ins(p,q,v);
        ins(q,p,v);
	}
	spfa(1);
    int t=a[n],now=n;
    while(now!=1)
    {
        c[++len]=z[now];
        now=x[now];
    }
    for(int i=1;i<=len;++i)
    {
        edge[c[i]].dis*=2;
        edge[c[i]^1].dis*=2;
        spfa(1);
        ans=max(ans,a[n]);
        edge[c[i]].dis/=2;
        edge[c[i]^1].dis/=2;
    }
	printf("%d",ans-t);
}
