#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int k,l;
char s[300];
int main()
{
	scanf("%s%d",s,&k);
	l=strlen(s);
	while(k--)
	{
		for(int i=0;i<=l-2;++i)
			if(s[i]>s[i+1])
			{
				for(int j=i;j<=l-2;++j)s[j]=s[j+1];
				break;
			}
		--l;
	}
	int i=0;
	while(i<l&&s[i]=='0')++i;
	if(i==l)printf("0");
	else for(int j=i;j<l;++j)printf("%c",s[j]);
}