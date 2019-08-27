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
#define bre break
#define con continue
#define prq priority_queue
#define Re register
#define bu bool
#define cz char
#define cst const
#define inl inline
#define next_pre next_premutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl void read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')k=c=='-'?-1:k,c=getchar();while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();a*=k;}
template<typename T>void write(T a,cz t=' '){if(a==0){putchar(48),putchar(t);return;}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(Re in i=le;i>=1;--i)putchar(c[i]);putchar(t);}
string s;
in len,ss,s1,s0,a[200];
in main()
{
	cin>>s;
	s[s.size()]=s[0];
	len=s.size();
	for(Re in i=0;i<len;++i){if(s[i]=='0')a[++s0]=i+1;if(s[i]=='1')++s1;}
	for(Re in i=1;i<=s0;++i)if(s[a[i]]=='0')++ss;
	if(s0*s0>ss*len)puts("ROTATE");
	if(ss*len>s0*s0)puts("SHOOT");
	if(s0*s0==ss*len)puts("EQUAL");
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

