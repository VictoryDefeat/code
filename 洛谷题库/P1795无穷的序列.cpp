#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
const int INF=2147483647;
const int NINF=-2147483648;
const int N=100010;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
#define cleaa(a) memset(a,-0x3f,sizeof a)
#define mul(a) a*a
#define cube(a) a*a*a
struct control
{
    int ct,val;
    control(int Ct,int Val=-1):ct(Ct),val(Val){}
    inline control operator()(int Val)
    {
        return control(ct,Val);
    }
}_endl(0),_prs(1),_setpre(2);
struct FastIO
{
    #define IOSIZE 1000000
    char in[IOSIZE],*p,*pp,out[IOSIZE],*q,*qq,ch[20],*t,b,K,prs;
    FastIO():p(in),pp(in),q(out),qq(out+IOSIZE),t(ch),b(1),K(6){}
    ~FastIO(){fwrite(out,1,q-out,stdout);}
    inline char getch()
    {
        return p==pp&&(pp=(p=in)+fread(in,1,IOSIZE,stdin),p==pp)?b=0,EOF:*p++;
    }
    inline void putch(char x)
    {
        q==qq&&(fwrite(out,1,q-out,stdout),q=out),*q++=x;
    }
    inline void puts(const char str[]){fwrite(out,1,q-out,stdout),fwrite(str,1,strlen(str),stdout),q=out;}
    inline void getline(string& s)
    {
        s="";
        for(register char ch;(ch=getch())!='\n'&&b;)s+=ch;
    }
    #define indef(T) inline FastIO& operator>>(T& x)\
    {\
        x=0;register char f=0,ch;\
        while(!isdigit(ch=getch())&&b)f|=ch=='-';\
        while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getch();\
        return x=f?-x:x,*this;\
    }
    indef(int)
    indef(long long)
    inline FastIO& operator>>(char& ch){return ch=getch(),*this;}
    inline FastIO& operator>>(string& s)
    {
        s="";register char ch;
        while(isspace(ch=getch())&&b);
        while(!isspace(ch)&&b)s+=ch,ch=getch();
        return *this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;register char f=0,ch;
        double d=0.1;
        while(!isdigit(ch=getch())&&b)f|=(ch=='-');
        while(isdigit(ch))x=x*10+(ch^48),ch=getch();
        if(ch=='.')while(isdigit(ch=getch()))x+=d*(ch^48),d*=0.1;
        return x=f?-x:x,*this;
    }
    #define outdef(_T) inline FastIO& operator<<(_T x)\
    {\
        !x&&(putch('0'),0),x<0&&(putch('-'),x=-x);\
        while(x)*t++=x%10+48,x/=10;\
        while(t!=ch)*q++=*--t;\
        return *this;\
    }
    outdef(int)
    outdef(long long)
    inline FastIO& operator<<(char ch){return putch(ch),*this;}
    inline FastIO& operator<<(const char str[]){return puts(str),*this;}
    inline FastIO& operator<<(const string& s){return puts(s.c_str()),*this;}
    inline FastIO& operator<<(double x)
    {
        register int k=0;
        this->operator<<(int(x));
        putch('.');
        x-=int(x);
        prs&&(x+=5*pow(10,-K-1));
        while(k<K)putch(int(x*=10)^48),x-=int(x),++k;
        return *this;
    }
    inline FastIO& operator<<(const control& cl)
    {
        switch(cl.ct)
        {
            case 0:putch('\n');break;
            case 1:prs=cl.val;break;
            case 2:K=cl.val;break;
        }
    }
    inline operator bool(){return b;}
}io;
int n,ans,a;
int main()
{
	io>>n;
	for(int i=1;i<=n;++i)
	{
		io>>a;
		int k=sqrt(a*8-7);
		if(k*k==a*8-7&&k&1)io<<1<<_endl;
		else io<<0<<_endl;
	}
    return 0;
}
