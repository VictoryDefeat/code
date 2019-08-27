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
int n;
ll l, r;
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> l >> r;
		cout << ((l + r) & 1 ? ((r - l + 1) / 2 % 9 * (l + r) % 9) % 9 : ((r - l + 1) % 9 * (l + r) / 2 % 9) % 9) << endl;
	}
}
void work()
{
	;
}
int main()
{
	init();
	work();
}