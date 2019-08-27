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
template<typename T>non print(T x){if(x>9)print(x/10);*O++=x%10+'0';}
template<typename T>non out(T a,cz t='\n'){print(a);*O++=t;}
non fresh(){fwrite(obuf,O-obuf,1,stdout);}
in sum,t,x,n,a[15]={0,0,4,4,4,4,4,4,4,4,16,4},s,m;
in main()
{
	//freopen("a.in","r",stdin);
	read(n);
	m=52-n;
	for(in i=1;i<=n;++i)read(x),s+=x,--a[i];
	t=21-s;
	for(in i=0;i<=t;++i)sum+=a[i];
	if(sum>=(m>>1))*O++='V',*O++='U',*O++='C',*O++='I';
	else *O++='D',*O++='O',*O++='S',*O++='T',*O++='A';
	fresh();
	//freopen(".out","w",stdout);
}

