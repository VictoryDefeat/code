#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
#define bre break
#define con continue
#define prq priority_queue
#define Re register
#define bu bool
#define cst const
#define inl inline
template<typename T>inline T Max(T a,T b){return a>b?a:b;}
template<typename T>inline T Min(T a,T b){return a<b?a:b;}
template<typename T>inline void read(T &a){a=0;T k=1;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}a*=k;}
template<typename T>void write(T a){if(a<10){putchar(a+'0');return;}write(a/10);putchar(a%10+'0');}
in n,r,f[6000][6000],ans,x,y,z;
in main()
{
    read(n);
    read(r);
    for(Re in i=1;i<=n;++i)
    {
        read(x);
        read(y);
        read(z);
        f[x+1][y+1]=z;
    }
    for(Re in i=1;i<=5001;++i)
        for(Re in j=1;j<=5001;++j)
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    for(Re in i=0;i<=5000-r;++i)
        for(Re in j=0;j<=5000-r;++j)
            ans=Max(ans,f[i+r][j+r]-f[i+r][j]-f[i][j+r]+f[i][j]);
    write(ans);
}

