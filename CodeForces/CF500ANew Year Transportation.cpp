#include<cstdio>
int n,now=1,to,a[50000];
int main()
{
    scanf("%d%d",&n,&to);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    while(now<to)
    {
        now+=a[now];
        if(now>to)
        {
            printf("NO");
            break;
        }
        if(now==to)
        {
            printf("YES");
            break;
        }
    }
}
