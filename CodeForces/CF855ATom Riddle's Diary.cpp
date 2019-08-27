#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
#define mian main
#define maxn 100+10
#define maxm 100000+10
#define _(a) read(a)
#define non void
#define inf 2147483647
#define bre break
#define con continue
#define prq priority_queue
#define re register
#define bu bool
#define cz char
#define cst const
#define ope operator
#define inl inline
#define upp upper_bound
#define low lower_bound
#define next_per next_permutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getc(stdin);while(c<'0'||c>'9')k=c=='-'?-1:k,c=getc(stdin);while(c>='0'&&c<='9')a=a*10+(c^48),c=getc(stdin);if(c!='.'){a*=k;return;}T t=0.1;while(c<'0'||c>'9')c=getc(stdin);while(c>='0'&&c<='9')a+=t*(c^48),c=getc(stdin),t*=0.1;a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
in n;
string s[200];
in main()
{
	read(n);
	for(re in i=1;i<=n;++i)cin>>s[i];
	for(re in i=1;i<=n;++i)
	{
		bu ok=0;
		for(re in j=1;j<i;++j)if(s[i]==s[j]){ok=1;break;}
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

