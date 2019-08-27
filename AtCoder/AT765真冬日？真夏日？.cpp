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
#define maxn 10000+10
#define maxm 10000+10
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
inl cz gc(){static cz buf[100000],*L=buf,*R=buf;return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;}
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=gc();while(c<'0'||c>'9')k=c=='-'?-1:k,c=gc();while(c>='0'&&c<='9')a=a*10+(c^48),c=gc();if(c!='.'){a*=k;return;}T t=0.1;while(c<'0'||c>'9')c=gc();while(c>='0'&&c<='9')a+=t*(c^48),c=gc(),t*=0.1;a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
in n,s1,s2,s3,s4,s5,s6;
lf a,b;
in main()
{
	read(n);
	for(re in i=1;i<=n;++i)
	{
		read(a),read(b);
		if(a>=35)++s1;
		if(30<=a&&a<35)++s2;
		if(25<=a&&a<30)++s3;
		if(b>=25)++s4;
		if(a>=0&&b<0)++s5;
		if(a<0)++s6;
	}
	write(s1),write(s2),write(s3),write(s4),write(s5),printf("%d\n",s6);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

