#include<cstdio>
int x,a[20],n;
int main()
{
    scanf("%d",&x);
    while(!(x%10))x/=10;
    while(x)
    {
        a[++n]=x%10;
        x/=10;
    }
    for(int i=1;i<=n/2;++i)
        if(a[i]!=a[n-i+1])
        {
            printf("NO");
            return 0;
        }
    printf("YES");
}
