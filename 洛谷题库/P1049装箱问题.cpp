#pragma G++ optimize (2)
#include<cstdio>
int max(int a,int b){return a>b?a:b;}
inline void read(int &a)
{
    char c=getchar();a=0;int k=1;
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}a*=k;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int main()
{
    int m,n,f[30000],a[50];
    read(m);read(n);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=n;i++)
        for(int v=m;v>=a[i];v--)
            f[v]=max(f[v],f[v-a[i]]+a[i]);
    write(m-f[m]);
}
