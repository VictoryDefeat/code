#include<bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
typedef double lf;
namespace IN
{
	const int MAX_INPUT=1000000;
	#define getc()(p1==p2&&(p2=(p1=buf)+inbuf->sgetn(buf,MAX_INPUT),p1==p2)?EOF:*p1++)
	char buf[MAX_INPUT],*p1,*p2;
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
const int N=100010;
ll sum,n,k,ans;
inline ll check(ll x)
{
    return (x*x+3*x);
}
int main()
{
    input(n,k);
    if(n==1)
    {
        put(0);
        return 0;
    }
    sum=(n+k)<<1;
    ll l=1,r=n;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)==sum)
        {
            put(n-mid);
            return 0;
        }
        if(check(mid)<sum)l=mid+1;
        else r=mid-1;
    }
}