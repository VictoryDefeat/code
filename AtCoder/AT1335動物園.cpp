#include<bits/stdc++.h>
int a,b,c,k,s,t;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
	if(s+t>=k)printf("%d\n",(a-c)*s+(b-c)*t);
	else printf("%d\n",a*s+b*t);
	return 0;
}