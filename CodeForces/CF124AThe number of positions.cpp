#include<cstdio>
#define min(a,b) (a)<(b)?(a):(b)
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    printf("%d",min(n-a,b+1));
}
