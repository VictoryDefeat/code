#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s1[205],s2[205];
int sum1[30],sum2[30],len1,len2,sum3[30],sum4[30];
int main()
{
    gets(s1);
    gets(s2);
    len1=strlen(s1);
    len2=strlen(s2);
    for(int i=0;i<len1;++i)
    {
        if(s1[i]>='a'&&s1[i]<='z')++sum3[s1[i]-'a'+1];
        else ++sum1[s1[i]-'A'+1];
    }
    for(int i=0;i<len2;++i)
    {
        if(s2[i]>='a'&&s2[i]<='z')++sum4[s2[i]-'a'+1];
        else ++sum2[s2[i]-'A'+1];
    }
    for(int i=1;i<=26;++i)
        if(sum1[i]<sum2[i]||sum3[i]<sum4[i])
        {
            printf("NO");
            return 0;
        }
    printf("YES");
}
