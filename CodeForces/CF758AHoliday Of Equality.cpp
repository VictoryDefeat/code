#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
int n,a[200],maxx,sum;//5
int main()
{//1
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxx=max(a[i],maxx);
    }
    for(int i=1;i<=n;i++)
        sum+=maxx-a[i];//2
    printf("%d",sum);
    //3
}
