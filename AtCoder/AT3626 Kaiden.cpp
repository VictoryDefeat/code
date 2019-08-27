#include <cstdio>
long long a,b,k,t;
int main()
{
    scanf("%lld%lld%lld",&k,&a,&b);
    if(a>=k){printf("1");return 0;}
    if(b>=a){printf("-1");return 0;}
    if((k-a)%(a-b)>=1)t=1;
    printf("%lld",((k-a)/(a-b)+t)*2+1);
}
