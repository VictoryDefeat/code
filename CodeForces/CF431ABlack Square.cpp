#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,d,ans;
string s;
int main()
{
    cin>>a>>b>>c>>d>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='1')ans+=a;
        if(s[i]=='2')ans+=b;
        if(s[i]=='3')ans+=c;
        if(s[i]=='4')ans+=d;
    }
    printf("%d",ans);
}
