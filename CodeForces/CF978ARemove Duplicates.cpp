#include<cstdio>
int n,a[100],b[2000],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(!b[a[i]])++ans;
        b[a[i]]=i;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)
        if(b[a[i]]==i)printf("%d ",a[i]);
}
