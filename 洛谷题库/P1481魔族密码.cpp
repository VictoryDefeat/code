#include<iostream>
#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
string s[3000];
int f[3000],n,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        f[i]=1;
        for(int j=1;j<i;++j)
            if(s[i].find(s[j])==0)
                f[i]=max(f[j]+1,f[i]);
        ans=max(f[i],ans);
    }
    printf("%d",ans);
}
