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
#define maxn 110
#define maxm 100010
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
#define next_pre next_premutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')k=c=='-'?-1:k,c=getchar();while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putchar(48),putchar(t);return;}if(a<0){a=-a;putchar('-');}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putchar(c[i]);putchar(t);}
in ans,n,m,w[maxn],c[maxn],f[maxm],r;
in main()
{
	read(n);
	read(m);
	for(re in i=1;i<=n;++i)read(w[i]),read(r),c[i]=r-w[i];
	for(re in i=1;i<=n;++i)
		for(re in j=w[i];j<=m;++j)
			f[j]=Max(f[j],f[j-w[i]]+c[i]);
	for(re in i=1;i<=m;++i)ans=Max(ans,f[i]+m-i);
	write(ans);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

