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
	template<typename T,typename ...Args>inline void output(T a,Args ...args)
	{
		output(a);output(args...);
	}
	template<typename T,typename ...Args> inline void output(const char ch,T a,Args ...args)
	{
		output(ch,a);output(ch,args...);
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
const int N=5;
const int mod=1000000007;
int n,t;
struct node
{
    ll a[N][N];
    node(){memset(a,0,sizeof(a));}
    inline void build(){for(int i=1;i<=3;++i)a[i][i]=1;}
	node operator *(const node &x)const
	{
    	node z;
    	for(int k=1;k<=3;++k)
        	for(int i=1;i<=3;++i)
            	for(int j=1;j<=3;++j)
                	z.a[i][j]=(z.a[i][j]+x.a[i][k]*this->a[k][j]%mod)%mod;
    	return z;
	}
}ans,base;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input(t);
    while(t--)
	{
        input(n);
        if(n<=3)
		{
            output(1);
            continue;
        }
        memset(ans.a,0,sizeof(ans.a));
    	for(int i=1;i<=3;++i)ans.a[i][i]=1;
    	memset(base.a,0,sizeof(base.a));
    	base.a[1][1]=base.a[1][3]=base.a[2][1]=base.a[3][2]=1;
		int p=n;
        do
		{
	        if(p&1)ans=ans*base;
        	base=base*base;
        	p>>=1;
    	}
		while(p);
        output(ans.a[2][1]);
    }
	return 0;
}