#include<cstdio>
#include<cmath>
//#include<algorithm>
#include<cctype>
#include<cstring>
//#include<queue>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
#define priority_queue prq
#define _(a) read(a)
#define out(a) write(a)
#define Re register
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T>inline void read(T &a)
{
    char c=getchar();int k=1;
    while(!isdigit(c)){c=='-'?k=-1:k=1;c=getchar();}
    while(isdigit(c)){a=a*10+c-'0';c=getchar();}a*=k;
}
template<typename T>void write(T x)
{
    int len=0,a[50];
    x<0?putchar('-'),x=-x:x=x;
    do{a[++len]=x%10;}while(x/=10);
    for(int i=len;i>=1;--i)putchar(a[i]+'0');
}
ll n,m,a[3000000];
bool check(in ans)
{
    ll sum=0;
    for(Re in i=1;i<=n;++i)if(a[i]>ans)sum+=a[i]-ans;
    return sum>=m;
}
int main()
{
    _(n);
    _(m);
    ll l=1,r=1;
    for(Re in i=1;i<=n;++i)_(a[i]),r=max(r,a[i]);
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    out(r);
}
