#include<iostream>
#include<string>
using namespace std;
string b,w[50];
int n,s,f[50];
bool check(string s,string m,int k)
{
    int ls=s.size();
    for(int i=0;i<k;i++)
    {
        if(s[ls-k+i]!=m[i])return 0;
    }
    return 1;
}
void add(string &s,string m,int k)
{
    int lm=m.size();
    for(int i=k;i<lm;i++)s+=m[i];
}
void DFS(string now)
{
    int x=now.size();
    s=max(s,x);
    for(int i=1;i<=n;i++)
    {
        if(f[i]>=2)continue;
        int mk=w[i].size();
        for(int j=1;j<=mk;j++)
        {
            if(check(now,w[i],j))
            {
                string t=now;
                add(t,w[i],j);
                if(t==now)continue;
                f[i]++;
                DFS(t);
                f[i]--;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    cin>>b;
    DFS(b);
    cout<<s;
}
