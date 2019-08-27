#include<cstdio>
int a[2000],n;
void add()
{
    int x=0;
    while(lc<=la||lc<=lb)
    {
        c[lc]=a[lc]+b[lc]+x;
        x=c[lc]/10;
        c[lc]%=10;
        lc++;
    }
    c[lc]=x;
    if(c[lc]==0)lc--;
}
int main()
{
    scanf("%d",&n);
}
