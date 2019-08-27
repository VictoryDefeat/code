#include<cstdio>
int k,l,s=1,sum;
int main()
{
    scanf("%d%d",&k,&l);
    if(l%k)
    {
        printf("NO");
        return 0;
    }
    for(sum=0;s<=l;++sum)
    {
        if(s==l)
        {
            printf("YES\n%d",sum-1);
            return 0;
        }
        s*=k;
        if(l%s!=0)
        {
            printf("NO");
            return 0;
        }
    }
}
