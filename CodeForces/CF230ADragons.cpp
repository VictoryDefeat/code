#include<cstdio>
#include<algorithm>
using namespace std;
struct dragon
{
    int need,have;
}a[2000];
int n,s;
bool cmp(dragon a,dragon b)
{
    return a.need==b.need?a.have>b.have:a.need<b.need;
}
int main()
{
    scanf("%d%d",&s,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].need,&a[i].have);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(s<a[i].need)
        {
            printf("NO");
            return 0;
        }
        s+=a[i].have;
    }
    printf("YES");
}
