#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[200000],b[200000],t,m,n,ans=1;
bool prime(long long x)
{
    if(x<2)return 0;
    for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
    return 1;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=1;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
        for(int i=1;i<=m;++i)scanf("%lld",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        int i=1,j=1;
        for(;i<=n;++i,++j)
        {
            if(a[i]!=b[j])
            {
                while(a[i]!=b[j])
                {
                    ans*=a[i];
                    ++i;
                }
            }
        }
        printf(prime(ans)?"YES\n":"NO\n");
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
}
