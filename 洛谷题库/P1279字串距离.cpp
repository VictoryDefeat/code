#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char s1[3000],s2[3000];
int k,f[3000][3000],len1,len2;
int main()
{
    cin>>s1+1;cin>>s2+1;cin>>k;
    len1=strlen(s1+1);
    len2=strlen(s2+1);
    for(int i=1;i<=len1;++i)f[i][0]=f[i-1][0]+k;
    for(int i=1;i<=len2;++i)f[0][i]=f[0][i-1]+k;
    for(int i=1;i<=len1;++i)
        for(int j=1;j<=len2;++j)
            f[i][j]=min(f[i-1][j]+k,min(f[i][j-1]+k,f[i-1][j-1]+abs((int)s1[i]-(int)s2[j])));
    printf("%d",f[len1][len2]);
}