#include<cstdio>
int n,tmp,sum;
template<typename T> T abs(T a){return a<0?-a:a;}
template<typename T> inline T gcd(T a,T b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&tmp);
        sum=gcd(sum,abs(tmp));
    }
    printf("%d",sum);
}
