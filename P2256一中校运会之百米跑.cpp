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
#define unsi unsigned
cz obuf[1<<23],*O=obuf,buf[1<<23],*L=buf,*R=buf;
inl cz gc(){ret L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;}
template<typename T>inl T Max(T a,T b){ret a>b?a:b;}
template<typename T>inl T Min(T a,T b){ret a<b?a:b;}
template<typename T>inl T Abs(T a){ret a<0?-a:a;}
template<typename T>inl bu read(T &a){bu ok=0;a=0;T k=1;cz c=gc();while(c<'0'||c>'9')k=c=='-'?-1:k,c=gc();while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();if(c!='.'){a*=k;ret ok;}T t=0.1;while(c<'0'||c>'9')c=gc();if(c>='0'&&c<='9')ok=1;while(c>='0'&&c<='9')a+=t*(c^48),c=gc(),t*=0.1;a*=k;ret ok;}
template<typename T,typename... Args>inl bu read(T& t,Args&... args){ret read(t)&read(args...);}
template<typename T>non print(T x){if(x<0)x=-x,*O++='-';if(x>9)print(x/10);*O++=x%10+'0';}
template<typename T>inl non out(T a,cz t='\n'){print(a);*O++=t;}
non fresh(){fwrite(obuf,O-obuf,1,stdout);}
in f[20000],n,m,a,b,k;
string s[20000],p,q;
in father(in x){ret f[x]==x?x:f[x]=father(f[x]);}
in find(string a){for(in i=1;i<=n;++i)if(s[i]==a)ret i;}
non merge(in x,in y)
{
    in a,b;
    a=father(x);
    b=father(y);
    f[b]=a==b?f[b]:a;
}
non finda(in x,in y)
{
    in a,b;
    a=father(x);
    b=father(y);
    printf(a==b?"Yes.\n":"No.\n");
}
in main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(in i=1;i<=n;++i)f[i]=i,cin>>s[i];
	for(in i=1;i<=m;++i)
	{
		cin>>p>>q;
		a=find(p),b=find(q);
		merge(a,b);
	}
	cin>>k;
	for(in i=1;i<=k;++i)
	{
		cin>>p>>q;
		a=find(p),b=find(q);
		finda(a,b);
	}
}

