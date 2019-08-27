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
#define next_per next_permutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getc(stdin);while(c<'0'||c>'9')k=c=='-'?-1:k,c=getc(stdin);while(c>='0'&&c<='9')a=a*10+(c^48),c=getc(stdin);if(c!='.'){a*=k;return;}T t=0.1;while(c<'0'||c>'9')c=getc(stdin);while(c>='0'&&c<='9')a+=t*(c^48),c=getc(stdin),t*=0.1;a*=k;}
template<typename T>non write(T a,cz t=' '){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
string s[60];
cz dx[]={-1,0,1,-1,1,-1,0,+1},dy[]={-1,-1,-1,0,0,1,1,1};
in n,m;
in main()
{
	read(n),read(m);
	for(re in i=0;i<n;++i)cin>>s[i];
	for(re in i=0;i<n;++i)
	{
		for(re in j=0;j<m;++j)
		{
			in count=0;
			if(s[i][j]!='#')
			{
				for(in k=0;k<8;++k)
          	      	if(0<=i+dx[k]&&i+dx[k]<n&&0<=j+dy[k]&&j+dy[k]<m&&s[i+dx[k]][j+dy[k]]=='#')++count;
                cout<<count;
            }
            else cout<<s[i][j];
		}
		cout<<endl;
	}
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

