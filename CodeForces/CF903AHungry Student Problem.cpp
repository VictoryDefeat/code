#include<cstdio>
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1||n==2||n==4||n==5||n==8||n==11)printf("NO\n");
        else printf("YES\n");
    }
}
