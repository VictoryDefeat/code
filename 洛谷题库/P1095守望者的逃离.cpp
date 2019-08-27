#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
#define maxn 300010
#define mod (1e9+7)
int n, m, t, f[maxn];
void init()
{
	scanf("%d%d%d", &m, &n, &t);
}
void work()
{
	for (int i = 1; i <= t; ++i)
		if (m >= 10)m -= 10, f[i] = f[i - 1] + 60;
		else f[i] = f[i - 1], m += 4;
	for (int i = 1; i <= t; ++i)f[i] = max(f[i], f[i - 1] + 17);
	if (f[t] >= n)
	{
		printf("Yes");
		for (int i = 1; i <= t; ++i)
			if (f[i] >= n)
			{
				printf("\n%d", i);
				break;
			}
	}
	else printf("No\n%d", f[t]);
}
int main()
{
	init();
	work();
}