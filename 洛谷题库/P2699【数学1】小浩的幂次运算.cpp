#include<cstdio>
#define ll long long
ll l,r,w,t=1;
bool ok=0;
int main()
{
    scanf("%lld%lld%lld",&l,&r,&w);
    if(l==1)
    {
        ok=1;
        printf("1 ");
    }
    if(w>1)
    {
        while(t<l/w||(t==l/w&&(l%w)))t*=w;
        while(t<=r/w)
        {
            t*=w;
            ok=1;
            printf("%lld ",t);
        }
    }
    if(!ok)printf("-1");
}
