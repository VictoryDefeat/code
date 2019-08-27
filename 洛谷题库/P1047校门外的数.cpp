#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    int i,j,L,m,x,y,t;
    cin>>L>>m;
    for (i=0;i<=L;i++)a[i]=1;
    for (i=1;i<=m;i++)
    {
        cin>>x>>y;
        for (j=x;j<=y;j++)a[j]=0;
    }
    t=0;
    for (i=0;i<=L;i++)t+=a[i];
    cout<<t;
}
