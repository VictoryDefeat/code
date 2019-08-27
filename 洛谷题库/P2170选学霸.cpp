
#include<cstdlib>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;
map<int,int>s;
int n,m,k,f[30000],a[30000],len,v[30000];
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
    f[find(a)]=f[find(b)];
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=1;i<=k;++i)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b))merge(a,b);
    }
    for(int i=1;i<=n;++i)f[i]=find(f[i]);
    for(int i=1;i<=n;++i)++s[f[i]];
    for(int i=1;i<=n;++i)if(s[i])a[++len]=s[i];
    v[0]=1;
    for(int i=1;i<=len;++i)
        for(int j=n-a[i];j>=0;--j)
            if(v[j])v[j+a[i]]=1;
    int ans=1<<30;
    for(int i=0;i<=n;++i)
        if(v[i]&&abs(i-m)<abs(ans-m))
            ans=i;
    cout<<ans;
    system("pause");
}