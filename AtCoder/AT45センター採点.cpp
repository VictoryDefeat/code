#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200],s[7];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%1d",&a[i]);
        ++s[a[i]];
    }
    sort(s+1,s+5);
    printf("%d %d\n",s[4],s[1]);
}
