#include<iostream>
using namespace std;
string a,b;
int main()
{
    cin>>a>>b;
    int len=a.size();
    for(int i=0;i<len;i++)
        if(a[i]==b[i])cout<<0;
        else cout<<1;
}
