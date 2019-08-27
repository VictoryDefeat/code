#include<bits/stdc++.h>
using namespace std;
#define reg register
#define sq(a) (a)*(a)
#define cu(a) (a)*(a)*(a)
typedef long long ll;
typedef double lf;
template<typename _T>inline void read(_T &x)
{
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	x*=f;
}
template<typename _T>void out(_T x)
{
	if(x<0)x=-x,putchar('-');
	if(x>9)out(x/10);
	putchar(x%10+48);
}
template<typename _T>inline void write(_T x,char c=' ')
{
	out(x);
	putchar(c);
}
const int N=100010;
int a,x,b,y,n;
int main()
{
    read(n),read(a),read(x),read(b),read(y);
    while(a!=x&&b!=y)
	{
        a=a%n+1;
        --b;
        if(b==0)b=n;
        if(a==b){puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}