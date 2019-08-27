#include<cstdio>
#include<iostream>
using namespace std;
string s1,s2;
int len1,len2,sum1,sum2;
int main()
{
    cin>>s1>>s2;
    len1=s1.size(),len2=s2.size();
    int i;
    for(i=0;i<len1&&s1[i]!='|';++i)++sum1;
    int t=i;
    for(i=i+1;i<len1;++i)++sum2;
    sum1-=sum2;
    if(len2-abs(sum1))
    {
        printf("Impossible");
        return 0;
    }
    if(sum1<0)
}
