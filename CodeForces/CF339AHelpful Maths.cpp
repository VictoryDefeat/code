#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100];
int main()
{
    while(cin>>a[++n]);
    n--;
    sort(a+1,a+1+n);
    printf("%d",a[1]);
    for(int i=2;i<=n;i++)printf("+%d",a[i]);
}
