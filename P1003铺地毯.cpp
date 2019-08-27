#include<cstdio>
struct carpet
{
    int a,b,g,k;
}a[10001];
int main()
{
    int n,x,y,s=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].g,&a[i].k);
        a[i].g+=a[i].a;
        a[i].k+=a[i].b;
    }
    scanf("%d%d",&x,&y);
    for(int i=n;i>=1;i--)
        if(a[i].g>=x&&x>=a[i].a&&a[i].k>=y&&y>=a[i].b){printf("%d",i);return 0;}
    printf("-1");
}
