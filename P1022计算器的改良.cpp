#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int u=1,v=1;
double sum1,sum2;
char c,s[50005],s1[50005];
int main()
{
    int i;
    cin>>s;
    int k=strlen(s);
    if(s[1]=='-')i=1;
    else
    {
        for(i=0;i<k;i++)s1[i+1]=s[i];
        s[0]='+';
        for(i=1;i<=k;i++)s[i]=s1[i];
        i=0;
    }
    for(i;i<=k;i++)
    {
        if(s[i]=='=')v=-1,s[i]=s[i+1]=='-'?s[i]:'+';
        if(s[i]=='+'||s[i]=='-')
        {
            if(s[i]=='+')u=1*v;
            else u=-1*v;
            int j=i+1,sum=0,e=0,l=1;
            for(j;j<=k;j++,e++)if(s[j]=='-'||s[j]=='+'||s[j]=='='||(s[j]>='a'&&s[j]<='z'))break;
            for(j=i+e;j>=i+1;j--)
            {
                sum+=(s[j]-'0')*l;
                l*=10;
            }
            if(s[i+e+1]>='a'&&s[i+e+1]<='z')c=s[i+e+1],sum1+=u*sum;
            else sum2+=-1*u*sum;
            i+=e;
        }
    }
    cout<<c<<'=';
    printf("%.3lf",sum2/sum1);
}
