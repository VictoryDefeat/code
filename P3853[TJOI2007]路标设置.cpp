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
in l,n,k,a[200000];
bool check(in mid)
{
	in sum=0;
	for(Re in i=2;i<=n+1;++i)if(a[i]-a[i-1]>mid){sum+=(a[i]-a[i-1])/mid;if((a[i]-a[i-1])%mid==0)--sum;}
	return sum<=k;
}
in main()
{
	read(l);
	read(n);
	read(k);
	a[0]=0;
	a[n+1]=l;
	for(Re in i=1;i<=n;++i)read(a[i]);
	in left=0,right=10000000;
	while(left<=right)
	{
		in mid=(left+right)>>1;
		if(check(mid))right=mid-1;
		else left=mid+1;
	}
	write(right+1);
}

