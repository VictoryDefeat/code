#include<cstdio>
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i)
        n=n%10?n-1:n/10;
    printf("%d",n);
}
