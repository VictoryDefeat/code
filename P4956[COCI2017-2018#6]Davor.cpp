#include<cstdio>
int n;
int main()
{
	scanf("%d",&n);
	n/=364;
	for(int i=100;i>=0;--i)
		if((n-i)%3==0&&i<n)
		{
			printf("%d\n%d",i,(n-i)/3);
			return 0;
		}
}
