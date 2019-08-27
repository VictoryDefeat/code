#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
typedef unsigned un;
typedef int in;
#define out break
#define con continue
#define prq priority_queue
#define Re register
template<typename T>T Max(T a,T b){return a>b?a:b;}
template<typename T>T Min(T a,T b){return a<b?a:b;}
in t,n,f[50],len,z[50];
int main()
{
    scanf("%d",&t);
    f[1]=1;
    f[2]=1;
    for(in i=3;i<=45;++i)f[i]=f[i-1]+f[i-2];
    while(t--)
    {
        memset(z,0,sizeof(z));
        len=0;
        scanf("%d",&n);
        in a=n;
        for(in i=45;i>=1;--i)
            if(f[i]<=a)
            {
                a-=f[i];
                z[++len]=f[i];
            }
        printf("%d=",n);
        for(in i=len;i>=1;--i)printf(i==1?"%d\n":"%d+",z[i]);
    }
}
