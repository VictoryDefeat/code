#include<cstdio>
#define min(a,b) a<b?a:b
void read(int &x)
{
    char c=getchar();x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int n,p,d[5000010],a[5000010],x,y,z;
int main()
{
    read(n);read(p);
    for(int i=1;i<=n;++i)
    {
        read(a[i]);
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=p;++i)
    {
        read(x);read(y);read(z);
        d[x]+=z;
        d[y+1]-=z;
    }
    int minn=d[1];
    for(int i=1;i<=n;++i)
    {
        a[i]=a[i-1]+d[i];
        minn=min(a[i],minn);
    }
    printf("%d",minn);
}
