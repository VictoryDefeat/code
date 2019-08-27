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
#define maxn 100010
#define mod (1e9+7)
string s;
int k, v[10][10], f[10], ans[101];
inline void Floyd()
{
  	for (int k = 0; k <= 9; ++k)
    	for (int i = 0; i <= 9; ++i)
      		for (int j = 0; j <= 9; ++j)
      			v[i][j] = v[i][j] || (v[i][k] && v[k][j]);
}
inline void init()
{
	cin >> s >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
	}
}
inline void work()
{
	for (int i = 0; i <= 9; ++i)v[i][i] = 1;
	Floyd();
	for (int i = 0; i <= 9; ++i)
		for (int j = 0; j <= 9; ++j)
			if (v[i][j]) ++f[i];
	int len = 2;ans[1] = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 1; j <= 100; ++j)ans[j] *= f[s[i] - '0'];
		for (int j = 1; j <= 100; ++j)
			if (ans[j] >= 10)
			{
				ans[j+1] += ans[j] / 10;
				ans[j] %= 10;
			}
		while (ans[len])++len;
	}
	for (int i = len - 1; i >= 1; --i)cout << ans[i];
}
int main()
{
	init();
	work();
}