#include<cstdio>
int a,b,p1,p2,p3,p4,sum;
int main()
{
    scanf("%d%d%d%d%d%d",&p1,&p2,&p3,&p4,&a,&b);
    for(int i=a;i<=b;++i)
        if((((i%p1)%p2)%p3)%p4==i)++sum;
    printf("%d",sum);
}
