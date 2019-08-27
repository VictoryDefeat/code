#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
#define maxn 300010
#define mod (1e9+7)
int n, d[maxn];
struct node
{
	int south, north;
} a[maxn];
void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i].south >> a[i].north;
}
bool cmp(node a, node b)
{
	return a.north < b.north;
}
void work()
{
	sort (a + 1, a + 1 + n, cmp);
	int len=0;
	d[++len] = a[1].south;
	for (int i = 2; i <= n; ++i)
	{
		int now = upper_bound(d + 1, d + 1 + len, a[i].south) - d;
		d[now] = a[i].south;
		if (now > len)++len;
	}
	cout << len;
}
int main()
{
	init();
	work();
}