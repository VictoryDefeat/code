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
#define next_pre next_premutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')k=c=='-'?-1:k,c=getchar();while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putchar(48),putchar(t);return;}if(a<0){a=-a;putchar('-');}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putchar(c[i]);putchar(t);}
in ans,n;
bu a[100000000];
in main()
{
 	cin>>n;
 	if(n<2){write(0);exit(0);}
 	ans=n;
 	ans-=n/2-1;
 	a[1]=1;
	for(re in i=3;i*i<=n;i+=2)
   	  	if(a[i]==0)
   		  	for(re in j=i*2;j<=n;j+=i)
  		   		if(a[j]==0&&j&1)--ans,a[j]=1;
 	write(--ans);
}
