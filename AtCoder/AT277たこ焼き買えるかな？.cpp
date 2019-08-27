#include<cstdio>
int n,sum;
int main()
{
    scanf("%d",&n);
    sum+=(n/10)*100;
    n%=10;
    if(n>=7)sum+=100;
    else sum+=n*15;
    printf("%d\n",sum);
}
