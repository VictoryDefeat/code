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
#define mian main
#define maxn 3
#define maxm 100000+10
#define _(a) read(a)
#define non void
#define inf 2147483647
#define bre break
#define con continue
#define prq priority_queue
#define re register
#define bu bool
#define cz char
#define cst const
#define ope operator
#define inl inline
#define upp upper_bound
#define low lower_bound
#define next_per next_permutation
template<typename T>inl T Max(T a,T b){return a>b?a:b;}
template<typename T>inl T Min(T a,T b){return a<b?a:b;}
template<typename T>inl T Abs(T a){return a<0?-a:a;}
template<typename T>inl non read(T &a){a=0;T k=1;char c=getc(stdin);while(c<'0'||c>'9')k=c=='-'?-1:k,c=getc(stdin);while(c>='0'&&c<='9')a=a*10+(c^48),c=getc(stdin);if(c!='.'){a*=k;return;}T t=0.1;while(c<'0'||c>'9')c=getc(stdin);while(c>='0'&&c<='9')a+=t*(c^48),c=getc(stdin),t*=0.1;a*=k;}
template<typename T>non write(T a,cz t='\n'){if(a==0){putc(48,stdout),putc(t,stdout);return;}if(a<0){a=-a;putc('-',stdout);}cz c[30];in le=0;while(a){c[++le]=a%10+48;a/=10;}for(re in i=le;i>=1;--i)putc(c[i],stdout);putc(t,stdout);}
ll n,p,a,b,m,x,y,ans;
struct node
{
    ll l,r,w,f;
}tree[maxn<<2];
non build(in k,in ll,in rr)
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r){tree[k].w=0;return;}
    in m=(ll+rr)>>1;
    build(k<<1,ll,m);
    build(k<<1|1,m+1,rr);
    tree[k].w=tree[k<<1].w+tree[k<<1|1].w;
}
inl non down(in k)
{
    tree[k<<1].f+=tree[k].f;
    tree[k<<1|1].f+=tree[k].f;
    tree[k<<1].w+=tree[k].f*(tree[k<<1].r-tree[k<<1].l+1);
    tree[k<<1|1].w+=tree[k].f*(tree[k<<1|1].r-tree[k<<1|1].l+1);
    tree[k].f=0;
}
non askp(in k)
{
    if(tree[k].l==tree[k].r){ans=tree[k].w;return;}
    if(tree[k].f)down(k);
    in m=(tree[k].l+tree[k].r)>>1;
    if(x<=m)askp(k<<1);
    else askp(k<<1|1);
}
non sump(in k)
{
    if(tree[k].l==tree[k].r){tree[k].w+=y;return;}
    if(tree[k].f)down(k);
    in m=(tree[k].l+tree[k].r)>>1;
    if(x<=m)sump(k<<1);
    else sump(k<<1|1);
    tree[k].w=tree[k<<1].w+tree[k<<1|1].w; 
}
non aski(in k)
{
    if(tree[k].l>=a&&tree[k].r<=b){ans+=tree[k].w;return;}
    if(tree[k].f)down(k);
    in m=(tree[k].l+tree[k].r)>>1;
    if(a<=m)aski(k<<1);
    if(b>m)aski(k<<1|1);
}
non sumi(in k)
{
    if(tree[k].l>=a&&tree[k].r<=b){tree[k].w+=(tree[k].r-tree[k].l+1)*y;tree[k].f+=y;return;}
    if(tree[k].f) down(k);
    in m=(tree[k].l+tree[k].r)/2;
    if(a<=m) sumi(k*2);
    if(b>m) sumi(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
in main()
{
    n=2;
    build(1,1,n);
    x=1,read(y);
    sump(1);
    x=2,read(y);
    sump(1);
    a=1,b=2;
    aski(1);write(ans);
}
