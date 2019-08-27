#include<cstdio>
int m,n,i=1;
int main()
{
    scanf("%d%d",&n,&m);
    while(m>=i)
    {
        m-=i;
        ++i;
        if(i>n)i=1;
    }
    printf("%d",m);
}
