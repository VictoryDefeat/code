#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
template<typename T>T Min(T a,T b){return a<b?a:b;}
template<typename T>T Min3(T a,T b,T c){return Min(Min(a,b),c);}
map<int,int>m;
int n,f[300][300],ans[90000],len;
string s[300];
int main()
{
	scanf("%d",&n);
	for(register int i=0;i<n;++i)cin>>s[i];
	for(register int i=0;i<=n;++i)f[i][0]=s[i][0]-48;
	for(register int i=0;i<=n;++i)f[0][i]=s[0][i]-48;
	for(register int i=1;i<n;++i)
		for(register int j=1;j<n;++j)
			if(s[i][j]=='1')
			{
				f[i][j]=Min3(f[i-1][j],f[i-1][j-1],f[i][j-1])+1;
				++m[f[i][j]];
			}
	for(register int i=n;i>0;--i)m[i-1]+=m[i];
	for(register int i=2;i<=n;++i)if(m[i])ans[++len]=i;
	for(register int i=1;i<=len;++i)printf(i==len?"%d %d":"%d %d\n",ans[i],m[ans[i]]);
}
