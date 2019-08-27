#include<cstdio>
int l;
char s[60];
int main()
{
    scanf("%d%s",&l,s);
    for(int i=0,n=0;i<l;i+=++n)printf("%c",s[i]);
    return 0;
}
