#include<bits/stdc++.h>
using namespace std;
#define reg register
#define sq(a) (a)*(a)
#define cu(a) (a)*(a)*(a)
typedef long long ll;
typedef double lf;
inline char nextchar(){static char buf[100000],*p1=buf,*p2=buf;return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
template<typename _T>inline void read(_T &x)
{
	_T f=1;
	char c=nextchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=nextchar();}
	while(c>='0'&&c<='9')x=x*10+(c^48),c=nextchar();
	x*=f;
}
template<typename _T>inline void write(_T x,char c=' ')
{
  	static int stk[100],top=0;
  	if(x==0){putchar('0');return;}
  	if(x<0){x=-x;putchar('-');}
  	while(x){stk[++top]=x%10;x/=10;}
  	while(top){putchar(stk[top--]+'0');}
	putchar(c);
}
const int N=300010;
int n,m,tmp,a[N][5];
char check(int x,int y){for(int i=1;i<=m;++i)if(a[i][0]!=x&&a[i][0]!=y&&a[i][1]!=x&&a[i][1]!=y)return 0;return 1;}
int main()
{
    read(n),read(m);
    for(int i=1;i<=m;++i)
    {
        read(a[i][0]),read(a[i][1]);
        if(a[i][0]!=a[1][0]&&a[i][0]!=a[1][1]&&a[i][1]!=a[1][0]&&a[i][1]!=a[1][1])tmp=i;
    }
    if(check(a[1][0],a[1][1])||check(a[1][0],a[tmp][0])||check(a[1][0],a[tmp][1])||check(a[1][1],a[tmp][0])||check(a[1][1],a[tmp][1])){puts("YES");return 0;}
	puts("NO");
	return 0;
}