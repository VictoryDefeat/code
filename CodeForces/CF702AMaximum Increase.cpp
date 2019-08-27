#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF=2147483647;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
#define maxn 100010
int n,a[maxn];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
}
void work()
{
	int len=1,ans=1;
	for(int i=2;i<=n;++i)
		if(a[i]>a[i-1])
			++len;
		else
		{
			ans=max(len,ans);
			len=1;
		}
	ans=max(len,ans);
	printf("%d",ans);
}
int main()
{
	init();
	work();
}