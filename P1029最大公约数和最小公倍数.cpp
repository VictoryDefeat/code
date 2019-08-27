#include<cstdio>
#include<cmath>
inline void read(int &a)
{
    int k=1;
    char c;a=0;
    c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}
    a*=k;
}
int m,n,s;
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int main()
{
    read(n);read(m);
    for(int i=1;i<=sqrt(m*n);i++)
    {
        if((n*m)%i==0&&gcd(i,(n*m)/i)==n)s++;
    }
    printf("%d",s*2);
}
