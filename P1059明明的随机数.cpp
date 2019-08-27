#include<cstdio>
#include<algorithm>
int a[101],n,s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    std::sort(a+1,a+1+n);
    s=n;
    for(int i=1;i<=n;i++)if(a[i]==a[i-1])s--;
    printf("%d\n",s);
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])printf("%d ",a[i]);
}
