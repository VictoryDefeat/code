#include<cstdio>
int n,x,s[5];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        s[x]++;
    }
    if(s[1]>s[2])printf("%d",s[2]+(s[1]-s[2])/3);
    else printf("%d",s[1]);
}
