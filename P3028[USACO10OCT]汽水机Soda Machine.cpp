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
#define next_pre next_premutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')k=c=='-'?-1:k,c=getchar();while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putchar(48),putchar(t);return;}if(a<0){a=-a;putchar('-');}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putchar(c[i]);putchar(t);}
struct kkk
{
	in p,v;
}a[maxn<<1];
bu ope <(cst kkk &a,cst kkk &b)
{
	return a.p==b.p?a.v>b.v:a.p<b.p;
}
in n,ans,sum;
in main()
{
	read(n);
	for(re in i=1;i<=n;++i)read(a[i].p),read(a[i+n].p),a[i].v=1,a[i+n].v=-1;
	sort(a+1,a+1+(n<<1));
	for(re in i=1;i<=n<<1;++i)sum+=a[i].v,ans=Max(sum,ans);
	write(ans);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

