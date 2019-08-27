#include<cstdio>
#include<cmath>
//#include<algorithm>
#include<cctype>
#include<cstring>
//#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
typedef string str;
#define priority_queue prq
#define _(a) read(a)
#define out(a) write(a)
#define Re register
//template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T>T min(T a,T b){return a<b?a:b;}
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
in n,q,x,y;
str s[10];
int main()
{
    _(n);
    _(q);
    for(Re in i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }
    while(q--)
    {
        _(x);
        _(y);
        in ans,ans1;
        for(ans=0;ans<=n;++ans)
            if(s[x][y-ans]!=s[x][y+ans])
                break;
        for(ans1=0;ans1<=n;++ans1)
            if(s[x-ans1][y]!=s[x+ans1][y])
                break;
        --ans;
        --ans1;
        out(max(ans1*2+1,ans*2+1));
        putchar('\n');
    }
}
