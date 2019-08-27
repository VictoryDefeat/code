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
int p[31];
void powr(int x)
{
    if(x==0)printf("0");
    else if(x==2)printf("2");
    else for(int i=30;i>=0;i--)
        if(x>=p[i])
        {
            if (i!=1)
            {         
                printf("2(");powr(i);printf(")");
            }
            else printf("2");
            x-=p[i];
            if(x)printf("+");
        }
}
int main()
{
    int t,n;
    for(int i=0;i<31;i++)p[i]=1<<i;
    read(n);
    powr(n);
}
