#include<iostream>
using namespace std;
string a;
int x,sum,sum1;
int main()
{
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;i++)
        if(a[i]=='1')
        {
            x=i;
            break;
        }
    for(int i=x+1;i<len;i++)
    {
        if(a[i]=='0')sum++;
        else sum1++;
        if(sum>6&&sum1)
        {
            cout<<"yes"<<endl;
            return 0;
        }
    }
    cout<<"no"<<endl;
}
