#include<cstdio>
int a[101],n,t,v,s=0;
int abs(int a)
{
    if(a<0)return -a;
    return a;
}
int main()
{
    int s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);s+=a[i];}
    int v=s/n;s=0;
    for(int i=1;i<=n;i++)a[i]-=v;
    for(int i=1;i<=n;i++){a[i+1]+=a[i];if(a[i])s++;}
    printf("%d\n",s);
}
