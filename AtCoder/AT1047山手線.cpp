#include<cstdio>
int a,b,c,s;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    while(s<=10000)
    {
       if(c<=a)
       {
           printf("%d\n",s+c);
           return 0;
       }
       s+=a+b;
       c=c-a-b<0?c-a-b+60:c-a-b;
   }
   printf("-1\n");
}
