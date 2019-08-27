#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef double lf;
const int N=100010;
int xx,yy,xxx,yyy,n,s[N],ans;
struct node
{
    int x,y;
}a[N];
bool cmp(node a,node b)
{
    int q=(xx-a.x)*(xx-a.x)+(yy-a.y)*(yy-a.y);
    int p=(xx-b.x)*(xx-b.x)+(yy-b.y)*(yy-b.y);
    return q<p;
}
int main(int argc,char ** argv)
{
    scanf("%d%d%d%d%d",&xx,&yy,&xxx,&yyy,&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>0;--i)s[i]=max(s[i+1],(xxx-a[i].x)*(xxx-a[i].x)+(yyy-a[i].y)*(yyy-a[i].y));
    ans=s[1];
    for(int i=1;i<=n;++i)
    {
        int sum=(xx-a[i].x)*(xx-a[i].x)+(yy-a[i].y)*(yy-a[i].y);
        sum+=s[i+1];
        ans=min(ans,sum);
    }
    ans=min(ans,s[1]);
    printf("%d",ans);
    return 0;
}