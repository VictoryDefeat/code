#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
#define bre break
#define con continue
#define prq priority_queue
#define Re register
template<typename T>inline T Max(T a,T b){return a>b?a:b;}
template<typename T>inline T Min(T a,T b){return a<b?a:b;}
template<typename T>inline void read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}a*=k;}
template<typename T>void write(T a){if(a<10){putchar(a+'0');return;}write(a/10);putchar(a%10+'0');}
in n,a[2000],f[2000];
void prime()
{
    for(in i=1;i<=n;++i)
    	for(in j=i*2;j<=n;j+=i)
			a[j]+=i;
}
in main()
{
	read(n);
	prime();
	for(Re in i=2;i<=n;++i)
		for(Re in j=n;j>=i;--j)
			f[j]=Max(f[j],f[j-i]+a[i]);
	write(f[n]);
}

