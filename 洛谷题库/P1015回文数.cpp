#include<cstdio>
#include<string>
#include<iostream>
#define ull unsigned long long
using namespace std;
string a;
ull n,k,l,m;
bool ok(ull a)
{
    ull s=0;
    for(ull i=a;i;i/=n)s=s*n+i%n;
    m=s+a;
    return s==a;
}
ull c(char a)
{
    return a>='0'&&a<='9'?a-'0':a-'A'+10;
}
int main()
{
    cin>>n>>a;l=a.size();
    for(int i=0;i<l;i++)k=k*n+c(a[i]);
    ull i=0;
    for(i;!ok(k)&&i<=30;i++)k=m;
    if(i<=30)printf("STEP=%d",i);
    else printf("Impossible!");
}
