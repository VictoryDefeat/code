#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string a[30];
int n;
bool cmp(string x,string y)
{
    return x+y>y+x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)cout<<a[i];
}
