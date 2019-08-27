#include<iostream>
using namespace std;
string n;
int sum,len;
int main()
{
    cin>>n;
    len=n.size();
    for(int i=0;i<len;i++)
        if(n[i]=='4'||n[i]=='7')
            sum++;
    if(sum==4||sum==7)
        cout<<"YES";
    else cout<<"NO";
}
