#include<cstdio>
#include<algorithm>
using namespace std;
long long x,sum,a[200000],n;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        sum+=x;
    }
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    if(sum<=a[n]+a[n-1])printf("YES");
    else printf("NO");
}
