#include<cstdio>
char c;
int l,s1,s2,ss1,ss2,f21[5000][10];
int main()
{
    while(1)
    {
    	scanf("%c",&c);
    	if(c=='E')break;
    	if(c=='W'){s1++;ss1++;}
    	if(c=='L'){s2++;ss2++;}
    	if((s1>=11&&s1-s2>=2)||(s2>=11&&s2-s1>=2)){printf("%d:%d\n",s1,s2);s1=s2=0;}
    	if((ss1>=21&&ss1-ss2>=2)||(ss2>=21&&ss2-ss1>=2)){l++;f21[l][1]=ss1;f21[l][2]=ss2;ss1=ss2=0;}
    }
    printf("%d:%d\n\n",s1,s2);
    for(int i=1;i<=l;i++)printf("%d:%d\n",f21[i][1],f21[i][2]);
    printf("%d:%d",ss1,ss2);
}
