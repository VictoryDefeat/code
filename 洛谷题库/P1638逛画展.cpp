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
in n,m,a[2000000],cnt[3000],ans=1<<30,ansl=1<<30;
in main()
{
	read(n);
	read(m);
	for(Re in i=1;i<=n;++i)read(a[i]);
	for(in l=1,r=0,now=0;l<=n;)
	{
		while(now<m&&r<n)now+=!cnt[a[++r]]++;
		if(now<m)bre;
		if(ans==r-l+1)ansl=Min(ansl,l);
  		if(ans>r-l+1)
		{
			ans=r-l+1;
  			ansl=l;
  		}
  		now-=!--cnt[a[l++]];
	}
	write(ansl);
	putchar(' ');
	write(ansl+ans-1);
}

