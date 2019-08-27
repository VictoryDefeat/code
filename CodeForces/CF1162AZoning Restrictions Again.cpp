#include<cstdio>
int min(int a,int b){return a<b?a:b;}
int n,h,m,limit[100],ans,l,r,x;
int main()
{
    scanf("%d%d%d",&n,&h,&m);
    for(int i=1;i<=n;++i)limit[i]=h;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&l,&r,&x);
        for(int i=l;i<=r;++i)limit[i]=min(x,limit[i]);
    }
    for(int i=1;i<=n;++i)ans+=limit[i]*limit[i];
    printf("%d",ans);
    return 0;
}
