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
#define maxn 700*700+10
#define maxm 700+10
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
	in high,x,y;
}a[maxn];
bu ope <(cst kkk &a,cst kkk &b){return a.high>b.high;}
bu visit[maxm][maxm];
in sum,h[maxm][maxm],n,m,dx[8]={-1,-1,-1,1,1,1,0,0},dy[8]={-1,0,1,-1,0,1,-1,1};
non dfs(in x,in y)
{
	visit[x][y]=1;
	for(re in i=0;i<8;++i)
	{
		in nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>n||ny<0||ny>m)con;
		if(h[nx][ny]<=h[x][y]&&!visit[nx][ny])dfs(nx,ny);
	}
}
in main()
{
	read(n),read(m);
	in now=0;
	for(re in i=1;i<=n;++i)
		for(re in j=1;j<=m;++j)
			read(a[++now].high),a[now].x=i,a[now].y=j,h[i][j]=a[now].high;
	sort(a+1,a+1+n*m);
	for(re in i=1;i<=n*m;++i)
		if(!visit[a[i].x][a[i].y])dfs(a[i].x,a[i].y),++sum;
	write(sum);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
}

