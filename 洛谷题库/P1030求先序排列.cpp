#include<string>
#include<iostream>
using namespace std;
void first(string middle,string last)
{
    if(middle.size())
    {
        char c=last[last.size()-1];
        cout<<c;
        int k=middle.find(c);
        first(middle.substr(0,k),last.substr(0,k));
        first(middle.substr(k+1),last.substr(k,middle.size()-1-k));
    }
}
int main()
{
    string middle,last;
    cin>>middle>>last;first(middle,last);
}
