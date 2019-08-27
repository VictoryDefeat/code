#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,s[2000];
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d",&x);
        s[x]++;
    }
    sort(s+1,s+1+n);
    printf("%d",s[1]);
}
