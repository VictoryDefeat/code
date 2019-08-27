#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
#define clear(a) memset(a, 0, sizeof a)
#define cleam(a) memset(a, 0x3f, sizeof a)
#define maxn 2000010
#define mod (1e9+7)
deque<int>q;
int n, k, a[maxn];
inline void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
}
inline void work()
{
	for (int i = 1; i <= n; ++i)
	{
		while (q.empty() == false && a[q.back()] >= a[i])q.pop_back();
		while (q.empty() == false && i + 1 - q.front() > k)q.pop_front();
		q.push_back(i);
		if (i >= k)cout << a[q.front()] << ' ';
	}
	cout << endl;
	while (!q.empty())q.pop_back();
	for (int i = 1; i <= n; ++i)
	{
		while (q.empty() == false && a[q.back()] <= a[i])q.pop_back();
		while (q.empty() == false && i + 1 - q.front() > k)q.pop_front();
		q.push_back(i);
		if (i >= k)cout << a[q.front()] << ' ';
	}
}
int main()
{
	init();
	work();
}
