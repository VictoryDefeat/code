#include <iostream>
#include <cmath>
using namespace std;
int death,hahaha,a[1000005],n;
bool b[1000005],gg[1000005];
bool isprime(int i)
{
    if (i<2) return 0;
    for (int j=2;j<=sqrt(i);j++)if(i%j==0)return 0;
    return 1;
}
int jiecheng(int i)
{
    int s=1;
    for (int j=1;j<=i;j++)s*=j;
    return s;
}
int sear(int depth)
{
    if (depth==0)
        if (isprime(hahaha)) return 1;
        else return 0;
    int s=0,t;
    for (int i=1;i<=n;i++)if (!b[i])
    b[i]=1,hahaha+=a[i],t=a[i],s+=sear(depth-1),hahaha-=t,b[i]=0;
    return s;
}
int main()
{
    int k,s=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        hahaha=a[i];
        b[i]=1;
        s+=sear(k-1);
        b[i]=0;
    }
    cout<<s/jiecheng(k);
}
