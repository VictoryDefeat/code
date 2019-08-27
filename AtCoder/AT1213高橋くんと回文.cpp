#include<cstdio>
#include<iostream>
using namespace std;
string s;
int n;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;++i)
        if(s[i]=='*')
            s[i]=s[n-i-1];
    for(int i=0;i<n;++i)
        if(s[i]!=s[n-i-1])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
}
