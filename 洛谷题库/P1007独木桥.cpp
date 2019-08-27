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
int main()
{
    int l,n,x;
    read(l);read(n);
    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        read(x);
        int a1=l-x+1,a2=x,t;
        if(a1>a2)t=a1,a1=a2,a2=t;
        if(a1>s1)s1=a1;
        if(a2>s2)s2=a2;
    }  
    printf("%d %d",s1,s2);
}
