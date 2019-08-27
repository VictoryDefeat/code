#include<cstdio>
typedef long long ll;
ll n,m,a[50005],l=n,f=1;
int main()
{
    scanf("%lld%lld\n",&n,&m);
    for(int i=1;i<=n;++i)
	{
        ll t=(ll)(n-i)*(n-i-1)/2;
        if(t>=m)a[f++]=i;
        else a[l--]=i,m-=(l-f+1);
    }
    for(int i=1;i<=n;++i)printf("%lld ",a[i]);
}
