#include<cstdio>
#include<iostream>
using namespace std;
string s[5];
int f[5];
int main()
{
    cin>>s[1]>>s[2]>>s[3];
    if(s[1][0]=='r')++f[1];
    else if(s[1][0]=='p')++f[2];
    else ++f[3];
    if(s[2][0]=='r')++f[1];
    else if(s[2][0]=='p')++f[2];
    else ++f[3];
    if(s[3][0]=='r')++f[1];
    else if(s[3][0]=='p')++f[2];
    else ++f[3];
    if((f[1]==1&&f[3]==2)||(f[2]==1&&f[1]==2)||(f[3]==1&&f[2]==2))
    {
        if(s[1]==s[2])cout<<'S';
        else if(s[2]==s[3])cout<<'F';
        else cout<<'M';
    }
    else cout<<'?';
}
