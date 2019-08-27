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
#define cst const
#define inl inline
template<typename T>inline T Max(T a,T b){return a>b?a:b;}
template<typename T>inline T Min(T a,T b){return a<b?a:b;}
template<typename T>inline void read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}a*=k;}
template<typename T>void write(T a){if(a<10){putchar(a+'0');return;}write(a/10);putchar(a%10+'0');}
in ans,n,t,k,v[200],f[2000],w[200];
in main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	read(t);
	read(k);
	for(Re in i=1;i<=n;++i)
	{
		read(w[i]);
		read(v[i]);
	    for(Re in j=v[i];j<=t*5/4;++j)f[j]=Max(f[j],f[j-v[i]]+w[i]);
	}
	ans=f[t];
    for(Re in i=1;i<=n;i++)if(v[i]>=k)ans=Max(ans,f[(t-v[i])*5/4]+w[i]);
    write(ans);
}

