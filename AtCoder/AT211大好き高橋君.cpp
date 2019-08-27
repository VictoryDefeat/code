#include<iostream>
#include<cstdio>
using namespace std;
int n,c;
string s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        if(s=="TAKAHASHIKUN"||s=="TAKAHASHIKUN."||s=="Takahashikun"||s=="Takahashikun."||s=="takahashikun"||s=="takahashikun.")
        ++c;
    }
    printf("%d\n",c);
}
