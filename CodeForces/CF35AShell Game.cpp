#include<cstdio>
int k,a,b;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&k);
    for(int i=1;i<=3;++i)
    {
        scanf("%d%d",&a,&b);
        if(k==a||k==b)k^=a^b;
    }
    printf("%d",k);
}
