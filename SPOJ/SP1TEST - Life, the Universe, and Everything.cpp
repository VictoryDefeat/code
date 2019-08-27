#include<cstdio>
int a[100000],n;
int main()
{
    while(1)
    {
        scanf("%d",&a[++n]);
        if(a[n]==42)
        {
            n--;
            break;
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",a[i]);
}
