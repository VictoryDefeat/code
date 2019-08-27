#include<cstdio>
#include<algorithm>
int n,a[400000],s[400000],x,sum;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        s[i]=a[i]+n-i+1;
    for(int i=1;i<=n;++i)
        x=std::max(x,s[i]);
    for(int i=n;i>=1;--i)
        if(a[i]+n>=x)++sum;
        else break;
    printf("%d",sum);
}
