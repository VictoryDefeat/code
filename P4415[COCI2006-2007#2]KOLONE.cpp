#include<cstdio>
#include<iostream>
using namespace std;
struct ant
{
    char name;
    int place;
}a[30];
int n1,n2,t,to[30];
int main()
{
    scanf("%d%d",&n1,&n2);
    for(int i=n1;i>=1;--i)
    {
        cin>>a[i].name;
        a[i].place=i;
        to[i]=1;
    }
    for(int i=n1+1;i<=n2+n1;++i)
    {
        cin>>a[i].name;
        a[i].place=i;
        to[i]=-1;
    }
    scanf("%d",&t);
    while(t--)
        for(int i=1;i<n1+n2;++i)
            if(to[a[i].place]==1&&to[a[i+1].place]==-1)
            {
                swap(a[i],a[i+1]);
                ++i;
            }
    for(int i=1;i<=n1+n2;++i)printf("%c",a[i].name);
}
