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
in n,l;
string word[700],s;
in main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	read(l);
	cin>>s;
	for(Re in i=1;i<=n;++i)cin>>word[i];
	
}

