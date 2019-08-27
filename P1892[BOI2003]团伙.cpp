#include<cstdio>
#include<iostream>
using namespace std;
int f[10000],n,m,a,b,p,enm[10000];
int father(int x)
{
    return f[x]==x?x:f[x]=father(f[x]);
}
void merge(int x,int y)
{
    int a,b;
    a=father(x);
    b=father(y);
    f[b]=a==b?f[b]:a;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int p,q;
        char c;
        cin>>c>>p>>q;
        if(c=='F')merge(p,q);
        if(c=='E')
        {
              if(enm[p]==0)enm[p]=father(q);
              else merge(q,enm[p]);
              if(enm[q]==0)enm[q]=father(p);
              else merge(p,enm[q]);
            }
    }
    int count[10000];
    for(int i=1;i<=n;i++)count[father(i)]++;
    int cnt=0;
    for(int i=1;i<=n;i++)if(count[i])cnt++;
    cout<<cnt;
}
