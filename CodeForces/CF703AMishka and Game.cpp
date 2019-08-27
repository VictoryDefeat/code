#include<cstdio>
int n,a,b,s1,s2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)s1++;
        if(a<b)s2++;
    }
    if(s1>s2)printf("Mishka");
    else if(s1<s2) printf("Chris");
    else printf("Friendship is magic!^^");
}
