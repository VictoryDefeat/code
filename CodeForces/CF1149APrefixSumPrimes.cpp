#include<bits/stdc++.h>
using namespace std;
#define reg register
#define sq(a) (a)*(a)
#define cu(a) (a)*(a)*(a)
typedef long long ll;
typedef double lf;
inline char nextchar(){static char buf[100000],*p1=buf,*p2=buf;return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
template<typename _T>inline void read(_T &x){x=0;_T f=1;char c=nextchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=nextchar();}while(c>='0'&&c<='9')x=x*10+(c^48),c=nextchar();x*=f;}
template<typename _T>inline void readf(_T &x){x=0;_T f=1,t=1.0;char c=nextchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=nextchar();}while(c>='0'&&c<='9')x=x*10+(c^48),c=nextchar();while(c<'0'||c>'9')c=nextchar();while(c>='0'&&c<='9')x+=t/10*(c^48),c=nextchar(),t/=10;x*=f;}
template<typename _T,typename... _Args>inline void read(_T& t,_Args&... args){read(t);read(args...);}
template<typename _T,typename... _Args>inline void readf(_T& t,_Args&... args){readf(t);readf(args...);}
template<typename _T>inline void write(_T x,char c=' '){static int stk[100],top=0;if(x==0){putchar('0');return;}if(x<0){x=-x;putchar('-');}while(x){stk[++top]=x%10;x/=10;}while(top){putchar(stk[top--]+'0');}putchar(c);}
template<typename _T>inline void out(_T x){static int stk[100],top=0;if(x==0){putchar('0');return;}if(x<0){x=-x;putchar('-');}while(x){stk[++top]=x%10;x/=10;}while(top){putchar(stk[top--]+'0');}putchar('\n');}
template<typename _T,typename... _Args>inline void write(_T t,_Args... args){write(t);write(args...);}
template<typename _T,typename... _Args>inline void out(_T t,_Args... args){out(t);out(args...);}
void writec(char *a,char c='\n'){int _len=strlen(a);for(int i=0;i<_len;++i)putchar(a[i]);putchar(c);}
void writes(string a,char c='\n'){int _len=a.size();for(int i=0;i<_len;++i)putchar(a[i]);putchar(c);}
const int N=100010;
int n,sum1,sum2,a;
int main()
{
    read(n);
    for(int i=1;i<=n;++i)
	{
        read(a);
        a==1?++sum1:++sum2;
    }
    if(sum2--)
	{
        write(2);
        if(sum1--)
		{
            write(1);
            while(sum2--)write(2);
            while(sum1--)write(1);
        }else while(sum2--)write(2);
    }
	else while(sum1--)write(1);
}