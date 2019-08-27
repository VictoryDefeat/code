#include<cstdio>
#include<iostream>
using namespace std;
int n,sum;
string a;
int main()
{
    scanf("%d",&n);
    cin>>a;
    for(int i=0;i<n;++i)
        if(a[i]==a[i+1])
            ++sum;
    printf("%d",sum);
}
