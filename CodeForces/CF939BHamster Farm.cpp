#include<cstdio>
#define ll long long
const ll inf=1ll<<62;
ll m,n,a,x,maxx,minn;
int main()
{
    scanf("%lld%lld",&m,&n);
    minn=inf;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        if(m%a<minn)
        {
            minn=m%a;
            x=a;
            maxx=i;
        }
    }
    printf("%lld %lld",maxx,m/x);
}
