#include<cstdio>
long long sum;
int n,x;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        sum+=x;
    }
    if(sum%2==0)printf("Bob");
    else printf("Alice");
}
