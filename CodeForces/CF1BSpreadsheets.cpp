#include<cstdio>
#include<cctype>
const char alp[]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char s[110];
int n;
bool flag;
void work1()
{
    int i=1,j=0,num1=0,num2=0,t[110];
    for(;isdigit(s[i]);++i)num2=num2*10+s[i]-'0';
    for(++i;s[i];++i)num1=num1*10+s[i]-'0';
    for(;num1;num1=num1/26-!(num1%26))
        if(num1%26)t[++j]=num1%26;
        else t[++j]=26;
    for(;j;--j)putc(alp[t[j]],stdout);
    printf("%d\n",num2);
}
void work2()
{
    int i=0,num1=0,num2=0;
    for(;isupper(s[i]);++i)num2=num2*26+s[i]-'A'+1;
    for(;s[i];++i)num1=num1*10+s[i]-'0';
    printf("R%dC%d\n",num1,num2);
}
int main()
{
    scanf("%d",&n);
    while(n)
	{
		--n;
        scanf("%s",s);
        flag=0;
        for(int i=0;s[i]&&!flag;++i)if(i&&isdigit(s[i-1])&&isupper(s[i]))flag=1;
        if(flag)work1();
        else work2();
    }
}
