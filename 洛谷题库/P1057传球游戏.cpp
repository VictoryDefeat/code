#pragma G++ optimize (2)
#include<cstdio>
int max(int a,int b){return a<b?b:a;}
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
int n,m,f[40][40];
int main()
{
    read(n);read(m);
    f[1][0]=1;
    for(int i=1;i<=m;i++)
    {
        f[1][i]=f[2][i-1]+f[n][i-1];
        f[n][i]=f[1][i-1]+f[n-1][i-1];
        for(int j=2;j<n;j++)f[j][i]=f[j-1][i-1]+f[j+1][i-1];
    }
    write(f[1][m]);
}
