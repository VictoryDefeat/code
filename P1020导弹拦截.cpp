#include<cstdio>
int a[200000],n;
int lis()
{
    int len=1,d[200000]={0};
    d[len]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=d[len])d[++len]=a[i];
        else
        {
            int l=1,r=len,m;
            while(l<r)
            {
                m=(l+r)>>1;
                if(a[i]<=d[m])l=m+1;
                else r=m;
            }
            d[l]=a[i];
        }
    }
    return len;
}
int s()
{
    int f[200000]={0},l=1;
    f[l]=a[1];
    for(int i=2;i<=n;i++)
    {
        int x=1<<30,id=0;
        bool ok=0;
        for(int j=1;j<=l;j++)if(f[j]>=a[i]&&f[j]<x){x=f[j];id=j;}
        if(id)f[id]=a[i];
        else f[++l]=a[i];
    }
    return l;
}
int main()
{
    int x;
    while(scanf("%d",&x)==1)a[++n]=x;
    printf("%d\n%d",lis(),s());
}
