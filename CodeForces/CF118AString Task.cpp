#include<cstdio>
#include<iostream>
using namespace std;
int len;
string s;
int main()
{
    cin>>s;
    len=s.size();
    for(int i=0;i<len;++i)
        if(s[i]!='A'&&s[i]!='a'&&s[i]!='O'&&s[i]!='o'&&s[i]!='Y'&&s[i]!='y'&&s[i]!='E'&&s[i]!='e'&&s[i]!='U'&&s[i]!='u'&&s[i]!='I'&&s[i]!='i')
        {
            cout<<'.';
            if (s[i]>='A'&&s[i]<='Z')cout<<(char)(s[i]+32);
            else cout<<s[i];
        }
}
