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
#define ret return
cz obuf[1<<23],*O=obuf,buf[1<<23],*L=buf,*R=buf;
inl cz gc(){ret L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;}
template<typename T>inl T Max(T a,T b){ret a>b?a:b;}
template<typename T>inl T Min(T a,T b){ret a<b?a:b;}
template<typename T>inl T Abs(T a){ret a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;cz c=gc();while(c<'0'||c>'9')k=c=='-'?-1:k,c=gc();while(c>='0'&&c<='9')a=a*10+(c^48),c=gc();if(c!='.'){a*=k;ret;}T t=0.1;while(c<'0'||c>'9')c=gc();while(c>='0'&&c<='9')a+=t*(c^48),c=gc(),t*=0.1;a*=k;}
template<typename T>non print(T x){if(x<0)x=-x,*O++='-';if(x>9)print(x/10);*O++=x%10+'0';}
template<typename T>inl non out(T a,cz t='\n'){print(a);*O++=t;}
non fresh(){fwrite(obuf,O-obuf,1,stdout);}
in k,n,l,s[1000];
non nto2()
{
	while(n)
	{
		s[++l]=(n&1);
		n>>=1;
	}
}
ll _2tok()
{
	ll t=0,base=1;
	for(in i=1;i<=l;++i)t+=s[i]*base,base*=k;
	ret t;
}
in main()
{
	//freopen("a.in","r",stdin);
	read(k),read(n);
	nto2();
	out(_2tok()),fresh();
	//freopen(".out","w",stdout);
}

