#include<cstdio>
int n,x,a,b,sa,sb;
int main()
{
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("NO");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(a==0)
        {
            a=x;
            sa++;
        }
        else if(b==0&&x!=a)
            {
                b=x;
                sb++;
            }
        else if(x==a)sa++;
        else if(x==b)sb++;
    }
    if(sa==sb&&sa==n/2)printf("YES\n%d %d",a,b);
    else printf("NO");
}
