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
template<typename T>non write(T a,cz t='\n'){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
in t,m,l,r,a[2000000],N=1000000,ps,p[700010];
bu f[2000000];
inl non Prime()
{
	a[1]=0;
	f[1]=1;
	for(in i=2;i<=N;++i)
	{
		if(!f[i])p[++ps]=i,a[i]=a[i-1]+1;
		else a[i]=a[i-1];
		for(in j=1;j<=ps&&p[j]*i<=N;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0)bre;
		}
	}
}
in main()
{
	freopen("P1865.in","r",stdin);
	Prime();
	read(t),read(m);
	while(t--)
	{
		read(l),read(r);
		if(r>m||l<1)printf("Crossing the line\n");
		else write(a[r]-a[l-1]);
	}
	//freopen(".out","w",stdout);
}

