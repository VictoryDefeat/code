#include<cstdio>
#include<algorithm>
using namespace std;
int n,sum,ans,t,a[20010],b[20010],x[40010],add[40010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i],&b[i]);
        x[++sum]=a[i],x[++sum]=b[i];
    }
    sort(x+1,x+1+sum);
    sum=unique(x+1,x+1+sum)-x-1;
    for(int i=1;i<=n;++i)
    {
        a[i]=lower_bound(x+1,x+sum+1,a[i])-x;
        b[i]=lower_bound(x+1,x+sum+1,b[i])-x;
    }
    for(int i=1;i<=n;++i)++add[a[i]],--add[b[i]];
    for(int i=1;i<sum;++i)
    {
        t+=add[i];
        if(t)ans+=x[i+1]-x[i];
    }
    printf("%d",ans);
}
