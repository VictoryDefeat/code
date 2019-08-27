#pragma G++ optimize (2)
#include<cstdio>
inline void read(int &a)
{
    int k=1;
    char c;a=0;
    c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}
    a*=k;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int v,n,t[30010],m[30010],f[30010];
int ma(int x,int y){return x>y?x:y;}
int main()
{
    read(v);read(n);
    for(int i=1;i<=n;i++)
    {
        int x;
        read(t[i]);read(x);
        m[i]=t[i]*x;
    }
    for(int i=1;i<=n;i++)
        for(int j=v;j>=t[i];j--)
            f[j]=ma(f[j-t[i]]+m[i],f[j]);
    write(f[v]);
}
