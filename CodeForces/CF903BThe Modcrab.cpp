#include<cstdio>
int h1,a1,c1,h2,a2,n,s[10010];
int main()
{
    scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
    while(h2>0)
        if(h1<=a2&&a1<h2)
        {
            s[++n]=1;
            h1+=c1;
            h1-=a2;
        }
        else
        {
            s[++n]=2;
            h2-=a1;
            h1-=a2;
        }
    printf("%d\n",n);
    for(int i=1;i<=n;i++)
        printf(s[i]==1?"HEAL\n":"STRIKE\n");
}
