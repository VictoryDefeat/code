#include<cstdio>
#include<cstdlib>
int n,m,v[500],f[500][500],ans,use[500],len,a[500];
inline bool ok(int x)
{
    bool c=1;
    for(register int i=1;i<=len;++i)if(!f[a[i]][x])c=0;
    return c;
}
inline void dfs(int now,int sum)
{
    if(sum>ans)ans=sum;
    for(register int i=1;i<=n;++i)
        if(now==1||(!use[i]&&ok(i)))
        {
            use[i]=1;
            a[++len]=i;
            dfs(now+1,sum+v[i]);
            use[i]=a[len--]=0;
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i)scanf("%d",&v[i]);
    for(register int i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        f[a][b]=1;
        f[b][a]=1;
    }
    dfs(1,0);
    printf("%d",ans);
    //system("pause");
}