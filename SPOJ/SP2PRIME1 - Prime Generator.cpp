#include<cstdio>
bool check(int x)
{
    if(x<2)return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int t,a,b;
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)if(check(i))printf("%d\n",i);
        printf("\n");
    }
}
