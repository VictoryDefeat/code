#include<cstring>
#include<cstdio>
char s1[1000],s2[1000],s3[1000];
int s,l;
int main()
{
    scanf("%s%d",s1,&s);
    l=strlen(s1);
    while(s--)
    {
        scanf("%s",s2);
        if(!strncmp(s1,s2,l))
        {
            if(!s3[0])strcpy(s3,s2);
            if(strcmp(s2,s3)<=0)strcpy(s3,s2);
        }
    }
    if(s3[0])printf("%s",s3);
    else printf("%s",s1);
}
