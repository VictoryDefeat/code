#include<cstdio>
struct node
{
    int hour,min;
}a[105];
int t[105],n,s;
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i].hour,&a[i].min);
        t[i]=a[i].hour*60+a[i].min;
    }
    bool ok=1;
    if(t[1]>=s+1){printf("0 0");return 0;}
    for(int i=2;i<=n;++i)
        if(t[i-1]+(s<<1)+2>t[i])continue;
        else
        {
            int p=t[i-1]+s+1;
            printf("%d %d",p/60,p%60);
            ok=false;
            break;
        }
    if(ok)
    {
        int p=t[n]+s+1;
        printf("%d %d",p/60,p%60);
    }
}
