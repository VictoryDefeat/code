#include<cstdio>
int gcd(int x,int y)
{
    return x%y==0?y:gcd(y,x%y);
}
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    a=gcd(a,b);
    scanf("%d",&b);
    printf("%d",gcd(a,b));
}
