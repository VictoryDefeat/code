#include<iostream>
#include<cstring>
using namespace std;
char s[600000];
int st=-1,las=-1,str=-1,lass=-1,len;
int main()
{
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;++i)if(s[i]=='['){st=i;break;}
    for(int i=len-1;i>=0;--i)if(s[i]==']'){las=i;break;}
    if(st==-1||las==-1){cout<<"-1";return 0;}
    for(int i=0;i<len;++i)if(s[i]==':'&&i>st){str=i;break;}
    for(int i=len-1;i>=0;--i)if(s[i]==':'&&i<las&&i>str){lass=i;break;}
    if(str==-1||lass==-1){cout<<"-1";return 0;}
    int ans=4;
    for(int i=str+1;i<lass;++i)if(s[i]=='|')ans++;
	cout<<ans;
}
