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
#define maxn 110
#define maxm 11
int mod(int a)
{
	return ((a % 10) + 10) % 10;
}
int n, m, a[maxn], b[maxn][maxn][maxm], s[maxn][maxn][maxm];
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 2; i <= n << 1; ++i)a[i] += a[i - 1];
}
void work()
{
	for (int l = 1; l <= n << 1; ++l)
      	for (int r = l; r <= n << 1; ++r)
        	b[l][r][1] = s[l][r][1] = mod(a[r] - a[l - 1]);
    for (int i = 2; i <= m; ++i)
      	for (int l = 1; l <= n << 1; ++l)
        	for (int r = l + i - 1; r <= n << 1; ++r)
          		s[l][r][i] = INF;
    for (int i = 2; i <= m; ++i)
      	for (int l = 1; l <= n << 1; ++l) 
        	for (int r = l + i - 1; r <= n << 1; ++r)
            	for (int k = l + i - 2; k < r; ++k)
            	{
            	    s[l][r][i] = min(s[l][r][i], s[l][k][i - 1] * mod(a[r] - a[k]));
                	b[l][r][i] = max(b[l][r][i], b[l][k][i - 1] * mod(a[r] - a[k]));
          		}
    int ans1 = 0, ans2 = INF;
    for (int i = 1; i <= n; ++i)
    {
        ans1 = max(ans1, b[i][i + n - 1][m]);
        ans2 = min(ans2, s[i][i + n - 1][m]);
    }
    cout << ans2 << endl << ans1;
}
int main()
{
	init();
	work();
}