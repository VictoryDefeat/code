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
#define maxn 510
#define mod (1e9+7)
int n, a[maxn];
void init()
{
	scanf("%d", &n);
	a[0] = 1; a[1] = 0;
}
void mul()
{
	for (int i = 1; i <= a[0]; ++i)
		a[i] *= 2;
	for (int i = 1; i <= a[0]; ++i)
		if (a[i] >= 10)a[i + 1] += a[i] / 10, a[i] %= 10;
	if (a[a[0] + 1])++a[0];
}
void add()
{
	a[1] += 2;
	for (int i = 1; i <= a[0]; ++i)
		if (a[i] >= 10)a[i + 1] += a[i] / 10, a[i] %= 10;
	if (a[a[0] + 1])++a[0];
}
void work()
{
	for (int i = 1; i <= n; ++i) {mul(); add();}
	int now = a[0];
	while (a[now] == 0 && now)--now;
	for (int i = now; i; --i)printf("%d", a[i]);
}
int main()
{
	init();
	work();
}