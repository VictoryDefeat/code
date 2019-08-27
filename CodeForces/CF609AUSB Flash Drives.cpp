#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,sum,ans,a[200];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=n;i>=1;--i)
    {
        sum+=a[i];
        ++ans;
        if(sum>=m)
        {
            printf("%d",ans);
            return 0;
        }
    }
}
