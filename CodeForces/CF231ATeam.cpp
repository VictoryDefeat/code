#include<cstdio>
int n,sum,a,b,c,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum=0;
        scanf("%d%d%d",&a,&b,&c);
        if(a)sum++;
        if(b)sum++;
        if(c)sum++;
        if(sum>=2)ans++;
    }
    printf("%d",ans);
}
