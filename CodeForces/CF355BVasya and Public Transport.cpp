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
#define clear(a) memset(a, 0, sizeof a)
#define cleam(a) memset(a, 0x3f, sizeof a)
#define maxn 100010
#define mod (1e9+7)
int n, m, c1, c2, c3, c4, a[2000], b[2000];
void init()
{
	ios::sync_with_stdio(false);
	cin.tie (0);cout.tie (0);
	cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= m; ++i)cin >> b[i];
}
void work()
{
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int ans1 = c4, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
	for (int k = 0; k <= 2; ++k)
		if (k == 1)
		{
			ans3 = ans4 = c3;
			for (int i = 1; i <= n; ++i)ans3 += min(a[i], c2);
			for (int i = 1; i <= m; ++i)ans4 += min(b[i], c2);
			ans3 = min(ans3, ans4);
		}
		else if (k == 0)
		{
			for (int i = 1; i <= n; ++i)ans2 += min(a[i], c2);
			for (int i = 1; i <= m; ++i)ans2 += min(b[i], c2);
		}
		else
			ans5 = c3 << 1;
	ans2 = min(ans2, ans3);
	ans2 = min(ans2, ans4);
	ans2 = min(ans2, ans5);
	ans1 = min(ans1, ans2);
	cout << ans1;
}
int main()
{
	init();
	work();
}