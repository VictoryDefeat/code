#include<cstdio>
int k,n,w,p,sum;
int main()
{
    scanf("%d%d%d",&k,&n,&w);
    while(w)
    {
        w--;
        sum+=++p*k;
    }
    printf("%d",sum-n<0?0:sum-n);
}
