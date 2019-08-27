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
template<typename T>non print(T x){if(x<0)x=-x,*O++='-';if(x>9)print(x/10);*O++=x%10+'0';}
template<typename T>inl non out(T a,cz t='\n'){print(a);*O++=t;}
non fresh(){fwrite(obuf,O-obuf,1,stdout);}
in sum[30],t,ma;
string s;
in conc(cz a){if(a>='A'&&a<='Z')ret a-'A'+1;if(a>='a'&&a<='z')ret a-32-'A'+1;ret 0;}
in main()
{
	//freopen("a.in","r",stdin);
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		getline(cin,s);
		in l=s.size();
		for(in i=0;i<l;++i)if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))++sum[conc(s[i])];
	}
	for(in i=1;i<=26;++i)ma=Max(sum[i],ma);
	for(in i=ma;i>=1;--i)
		for(in j=1;j<=26;++j)
			if(sum[j]==i)
				printf("%c %d\n",j+'A'-1,i);
	//fresh();
	//freopen(".out","w",stdout);
}

