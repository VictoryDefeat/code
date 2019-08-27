#include<cstdio>
int n,m,k,x;
int pow(int x,int n,int mod)
{
    int res=1;
	while(n)
	{
	   	if(n&1)res=(res*x)%mod;
	   	x=(x*x)%mod;
	   	n>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d",(x%n+m%n*pow(10,k,n))%n);
}
