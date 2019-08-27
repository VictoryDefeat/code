#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000
int Next[maxn],a,f[maxn],head[maxn],cmpi[maxn],out[maxn],e[maxn],cmp[maxn],s[maxn],dfn[maxn],low[maxn],top,cmpid,tim;
bool v[maxn],d[maxn];
void ins(int x,int y,int i)
{
    e[i]=y;
    Next[i]=head[x];
    head[x]=i;
}
int find()
{
    int ans=0;
    for(int i=1;i<=a;i++)
        for(int p=head[f[i]];p;p=Next[p])
            if(!d[e[p]])ans++;
    return ans;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++tim;
    s[++top]=u;
    v[u]=true;
    for(int p=head[u];p;p=Next[p])
    {
        int y=e[p];
        if(!dfn[y])
        {
            tarjan(y);
            low[u]=min(low[y],low[u]);
        }
        else
            if(v[y])low[u]=min(low[u],dfn[y]);
    }
    if(dfn[u]==low[u])
    {
        int y;
        cmpid++;
        do
        {
            y=s[top--];
            v[y]=false;
            f[++a]=y;
            d[y]=true;
            cmpi[cmpid]++;
        }while(y!=u);
        cmp[cmpid]=find();
        a=0;
        memset(d,false,sizeof(d));
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ins(a,b,i);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    int c=0,ans;
    for(int i=1;i<=cmpid;i++)
        if(!cmp[i])c++,ans=i;
    if(c==1)printf("%d",cmpi[ans]);
    else printf("0");
}
