#include<iostream>
int a[100],n,s[100];
void add()
{
    int xy[100]={0};
    xy[0]=s[0]>a[0]?s[0]:a[0];
    for(int i=1;i<=xy[0];i++)
    {
        xy[i]+=s[i]+a[i];
        xy[i+1]=xy[i]/10;
        xy[i]%=10;
    }
    while(xy[xy[0]+1]>0)
    {
        xy[xy[0]+2]=xy[xy[0]+1]/10;
        xy[xy[0]+1]%=10;
        xy[0]++;
    }
    s[0]=xy[0];
    for(int i=1;i<=xy[0];i++)s[i]=xy[i];
}
int main()
{
    int xy[100]={0};
    std::cin>>n;
    a[0]=1;
    a[1]=1;
    s[0]=1;
    s[1]=0;
    for(int y=1;y<=n;y++)
    {
    	for(int i=1;i<=xy[0];i++)xy[i]=0;
        xy[0]=a[0];
        for(int i=1;i<=a[0];i++)
        {
          xy[i]+=a[i]*y;
          xy[i+1]=xy[i]/10;
          xy[i]%=10;
        }
        while(xy[xy[0]+1]>0) 
        {
            xy[xy[0]+2]=xy[xy[0]+1]/10;
            xy[xy[0]+1]%=10;
            xy[0]++;
        }
        for(int i=1;i<=xy[0];i++)a[i]=xy[i];
        a[0]=xy[0];
        add();
    }
    for(int i=s[0];i>=1;i--)std::cout<<s[i];
}

