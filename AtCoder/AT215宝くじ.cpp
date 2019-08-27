#include<cstdio>
int s[11],sp,x,sum,ss;
int main()
{
    for(int i=1;i<=6;++i)
    {
        scanf("%d",&x);
        ++s[x];
    }
    scanf("%d",&sp);
    for(int i=1;i<=6;++i)
    {
        scanf("%d",&x);
        sum+=s[x];
        if(s[x]==0&&x==sp)ss=1;
    }
    if(sum==6)printf("1\n");
    else if(sum==5&&ss)printf("2\n");
    else if(sum==5)printf("3\n");
    else if(sum==4)printf("4\n");
    else if(sum==3)printf("5\n");
    else printf("0\n");
}
