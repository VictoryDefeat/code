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
int a,n,m,x,ans,k,xi[250],ch[250],s1[250],s2[250];
int main()
{
    read(a);read(n);read(m);read(x);
    xi[2]=1;n--;
    for(int i=3;i<=n;i++)xi[i]+=xi[i-1]+xi[i-2];
    ch[1]=ch[2]=ch[3]=ch[4]=a;
    for(int i=5;i<=n;i++)ch[i]+=ch[i-1]+ch[i-2];
    for(int i=3;i<=n;i++)
    {
        s2[i]+=s2[i-1]+ch[i-2];
        s1[i]+=s1[i-1]+xi[i-2];
    }
    for(int i=1;i<=0x7fff;i++)
        if(s1[n]*i+s2[n]==m)
        {
            k=i;break;
        }
    ans=s1[x]*k+s2[x];
    write(ans);
}
