#include <cstdio>
int main()
{
  	int n,f[20]={1,1};
  	scanf("%d",&n);
    for(int i=2;i<=n;i++)
   		for(int j=0;j<i;j++)
   			f[i]+=f[j]*f[i-j-1];
   printf("%d",f[n]);
}
