#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
	template<typename T,typename ...Args>inline int input(T& a,Args& ...args)
	{
		return input(a)&&input(args...);
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
	template <typename T>inline void put(T x)
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
	template<typename T>inline void put(const char ch,T x)
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
	template<typename T,typename ...Args>inline void put(T a,Args ...args)
	{
		put(a);put(args...);
	}
	template<typename T,typename ...Args> inline void put(const char ch,T a,Args ...args)
	{
		put(ch,a);put(ch,args...);
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
using OUT::put;
using OUT::putc;
using OUT::putst;
const int N=250010;
char l[20],r[20];
int e,f[N];
bool a[N];
gp_hash_table<string,int>m;
int find(int x)
{
    int t=f[x],p;
	while(t!=f[t])t=f[t];
    while(f[x]!=t){p=f[x];f[x]=t;x=p;}
    return t;
}
int main()
{
    while(scanf("%s%s",l,r)!=EOF)
    {
        if(!m[l])m[l]=++e,f[e]=e;
        if(!m[r])m[r]=++e,f[e]=e;
        if(e>N)
        {
            putst("Impossible\n");
            return 0;
        }
        a[m[l]]^=1;
        a[m[r]]^=1;
        f[find(m[l])]=find(m[r]);
    }
    int ok=0;
    for(int i=1;i<=e;++i)
		if(a[i])
		{
        	if(ok==2)
        	{
        		putst("Impossible\n");
        		return 0;
        	}
        	else ++ok;
		}
    int fa=find(1);
    for(int i=2;i<=e;++i)
		if(find(i)^fa)
    	{
        	putst("Impossible\n");
        	return 0;
    	}
    putst("Possible\n");
    return 0;
}