#include<bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
typedef double lf;
namespace IN
{
	const int Max_Input_Number=1000000;
	#define getc()(p1==p2&&(p2=(p1=buf)+inbuf->sgetn(buf,Max_Input_Number),p1==p2)?EOF:*p1++)
	char buf[Max_Input_Number],*p1,*p2;
	template<typename T>inline int input(T &x)
	{
		static std::streambuf *inbuf=cin.rdbuf();
		x=0;
		register int f=0,flag=1;
		register char ch=getc();
		if(ch==EOF)return EOF;
		while(!std::isdigit(ch))
		{
			if(ch=='-')f=1;
			ch=getc();
		}
		if(std::isdigit(ch))x=x*10+(ch&15),ch=getc(),flag=true;
		while(std::isdigit(ch))
		{
			x=x*10+(ch&15);
			ch=getc();
		}
		x=f?-x:x;
		return ch==EOF?EOF:flag;
	}
	template<typename T,typename ...Args>inline int input(T& logg,Args& ...args)
	{
		return input(logg)&&input(args...);
	}
	inline int readc(char &ch)
	{
		static std::streambuf *inbuf=cin.rdbuf();
		return (ch=getc())==EOF?EOF:0;
	}
	inline int readst(char *st)
	{
		if(readc(*st)!=EOF&&(*st))while(readc(*(++st))!=EOF&&*st!='\n');
		else return EOF;
		return 0;
	}
}
namespace OUT
{
	template <typename T>inline void output(T x)
	{
		static std::streambuf *outbuf=cout.rdbuf();
		static char stack[21];
		static int top=0;
		if(x<0)
		{
			outbuf->sputc('-');
			x=-x;
		}
		if(!x)
		{
			outbuf->sputc('0');
			outbuf->sputc('\n');
			return;
		}
		while(x)
		{
			stack[++top]=x%10+'0';
			x/=10;
		}
		while(top)
		{
			outbuf->sputc(stack[top]);
			--top;
		}
		outbuf->sputc('\n');
	}
	inline void putc(const char ch)
	{
		static std::streambuf *outbuf=cout.rdbuf();
		outbuf->sputc(ch);
	}
	template<typename T>inline void output(const char ch,T x)
	{
		static std::streambuf *outbuf=cout.rdbuf();
		static char stack[21];
		static int top=0;
		if(x<0)
		{
			outbuf->sputc('-');
			x=-x;
		}
		if(!x)
		{
			outbuf->sputc('0');
			outbuf->sputc(ch);
			return;
		}
		while(x)
		{
			stack[++top]=x%10+'0';
			x/=10;
		}
		while(top)
		{
			outbuf->sputc(stack[top]);
			--top;
		}
		outbuf->sputc(ch);
	}
	template<typename T,typename ...Args>inline void output(T logg,Args ...args)
	{
		output(logg);output(args...);
	}
	template<typename T,typename ...Args> inline void output(const char ch,T logg,Args ...args)
	{
		output(ch,logg);output(ch,args...);
	}
	inline void putst(const char *st)
	{
		static std::streambuf *outbuf=cout.rdbuf();
		int _len=strlen(st);
		const char *p=st;
		do{outbuf->sputc(*st);st++;}while(st+1<p+_len);
	}
}
using IN::input;
using IN::readc;
using IN::readst;
using OUT::output;
using OUT::putc;
using OUT::putst;
const int N=500010;
struct node
{
    int t,next;
}edge[N<<1];
int d[N],fat[N][30],logg[N],head[N],num,n,m,s;
void ins(int x,int y)
{
    edge[++num].t=y;
    edge[num].next=head[x];
    head[x]=num;
}
void dfs(int f,int fa)
{
    d[f]=d[fa]+1;
    fat[f][0]=fa;
    for(int i=1;(1<<i)<=d[f];++i)
    	fat[f][i]=fat[fat[f][i-1]][i-1];
    for(int i=head[f];i;i=edge[i].next)
    	if(edge[i].t!=fa)
        	dfs(edge[i].t,f);
}
int lca(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])x=fat[x][logg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int k=logg[d[x]]-1;k>=0;--k)
    	if(fat[x][k]!=fat[y][k])
        	x=fat[x][k],y=fat[y][k];
    return fat[x][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input(n,m,s);
    for(int i=1;i<=n-1;++i)
    {
        int x,y;input(x,y);
        ins(x,y);
		ins(y,x);
    }
    dfs(s,0);
    for(int i=1;i<=n;++i)
    	logg[i]=logg[i-1]+(1<<logg[i-1]==i);
    for(int i=1;i<=m;++i)
    {
        int x,y;
		input(x,y);
        output(lca(x,y));
    }
}