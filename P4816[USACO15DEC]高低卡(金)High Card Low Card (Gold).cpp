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
#define maxn 50000+10
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
template<typename T>inl non write(T a,cz t=' '){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
in n,a[maxn],b[maxn],now,sum;
bu m[maxm];
in main()
{
	read(n);
	for(in i=1;i<=n>>1;++i)read(a[i]),m[a[i]]=1;
	for(in i=1;i<=n>>1;++i)read(b[i]),m[b[i]]=1;
	sort(a+1,a+1+(n>>1));
	sort(b+1,b+1+(n>>1));
	now=n<<1;
	for(in i=n>>1;i>=1;--i)
	{
		while(m[now]&&now>=1)--now;
		if(now<a[i])con;
		else m[now]=1,++sum;
	}
	now=1;
	for(in i=1;i<=n>>1;++i)
	{
		while(m[now]&&now<=n<<1)++now;
		if(now>b[i])con;
		else m[now]=1,++sum;
	}
	write(sum);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

