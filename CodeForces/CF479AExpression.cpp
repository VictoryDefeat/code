#include<cstdio>
int a,b,c,ans1,ans2,ans3,ans4,ans5,ans6,ans;
int max(int a,int b){return a>b?a:b;}
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    ans1=a+b+c;
    ans2=a+b*c;
    ans3=a*b+c;
    ans4=a*b*c;
    ans5=(a+b)*c;
    ans6=a*(b+c);
    ans=max(ans1,ans2);
    ans=max(ans,ans3);
    ans=max(ans,ans4);
    ans=max(ans,ans5);
    ans=max(ans,ans6);
    printf("%d",ans);
    return 0;
}
