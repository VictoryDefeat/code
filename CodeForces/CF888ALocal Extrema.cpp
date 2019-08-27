#include<cstdio>
int n,a[2000],sum;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<n;i++)
    {
        if((a[i]>a[i+1]&&a[i]>a[i-1])||(a[i]<a[i+1]&&a[i]<a[i-1]))sum++;
    }
    printf("%d",sum);
}
