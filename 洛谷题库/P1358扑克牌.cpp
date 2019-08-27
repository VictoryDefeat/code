#include<cstdio>
int n,m,a[20000],s,jc[20000],z;
int sw(int x,int k)
{
    int t=1;
	x%=10007;
    while(k)
	{
        if(k&1)t*=x,t%=10007;
        x*=x;
		x%=10007;
        k>>=1;
    }
    return t;
}
int main()
{
    scanf("%d%d",&n,&m);
	jc[0]=1;
    for(int i=1;i<=m;i++)scanf("%d",&a[i]),s+=a[i];
    for(int i=1;i<=20000;i++)jc[i]=(jc[i-1]*i)%10007;
    z=(jc[n]*sw(jc[s]*jc[n-s],10005))%10007;
    for(int i=1;i<=m;i++)
	{
        z=(z*((jc[s]*sw(jc[a[i]]*jc[s-a[i]],10005))%10007))%10007;
        s-=a[i];
	}
	printf("%d",z);
}
