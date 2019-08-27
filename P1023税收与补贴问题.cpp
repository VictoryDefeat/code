#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200000],b[200000],l1,l2,r1,r2,p,n=1,x,y;
double ans1,ans2;
int main()
{
 	scanf("%d%d%d",&p,&a[1],&b[1]);
    while(1)
    {
        scanf("%d%d",&r1,&r2);
        if(r1==-1&&r2==-1)break;
        l1=a[n];l2=b[n];
        for(int i=l1+1;i<=r1;i++)
        {
            n++;
            a[n]=a[n-1]+1;
            b[n]=b[n-1]+(r2-l2)/(r1-l1);
        }
    }
    scanf("%d",&x);
    if(p>=a[n])
    {
        l1=a[n];l2=b[n];
        for(int i=l1+1;i<=p+1;i++)
        {
            n++;
            a[n]=a[n-1]+1;
            b[n]=b[n-1]-x;
        }
    }
    for(int i=1;i<=n;i++)
        if(a[i]==p)
        {
            y=b[i];
            break;
        }
    ans1=-(1<<30);
    ans2=1<<30;
    for(int i=1;i<=n;i++)
        if(y-b[i]>0)
            ans1=max(ans1,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*y)/(double)(y-b[i]));
		else
            ans2=min(ans2,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*y)/(double)(y-b[i]));
    if(ans1>ans2)printf("NO SOLUTION");
	else if(ans1>0)printf("%.0lf",ceil(ans1));
	else if(ans2<0)printf("%.0lf",floor(ans2));
	else printf("0");
}
