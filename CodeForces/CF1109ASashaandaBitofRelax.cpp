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
	x=0;
	_T f=1;
	char c=nextchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=nextchar();}
	while(c>='0'&&c<='9')x=x*10+(c^48),c=nextchar();
	x*=f;
}
template<typename _T,typename... _Args>inline void read(_T& t,_Args&... args){read(t);read(args...);}
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
int a,k,n;
ll ans;
map<pair<int,int>,int>m;
int main()
{
    read(n);
    pair<int,int>t;
    t.first=0,t.second=1;
    m[t]++;
    for(int i=1;i<=n;++i)
    {
        read(a);
        k^=a;
        int x=!(i&1);
        pair<int,int>p;
        p.first=k,p.second=x;
        ans+=m[p];
        ++m[p];
    }
    write(ans);
}