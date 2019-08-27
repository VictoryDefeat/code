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
#define maxn 210
#define mod (1e9+7)
int n, ans1 = INF, ans2, f[maxn][maxn], g[maxn][maxn], a[maxn], s[maxn];
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n << 1; ++i)s[i] = s[i - 1] + a[i];
}
void work()
{
    for (int l = 1; l < n; ++l)
        for(int i = 1, j = i + l; (j < n << 1) && (i < n << 1); ++i, j = i + l)
        {
            g[i][j] = INF;
            for(int k = i; k < j; ++k)
            {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
                g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    for (int i = 1; i <= n; ++i)
    {
        ans1 = min(ans1, g[i][i + n - 1]);
        ans2 = max(ans2, f[i][i + n - 1]);
    }
    cout << ans1 << endl << ans2;
}
int main()
{
	init();
	work();
}