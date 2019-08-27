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
const int NINF = - 2147483648;
#define clear(a) memset(a, 0, sizeof a)
#define cleam(a) memset(a, 0x3f, sizeof a)
#define cleaa(a) memset(a, - 0x3f, sizeof a)
#define maxn 50010
#define maxm 100
#define mod (1e9 + 7)
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 23, stdin), p1 == p2) ? EOF : *p1++)
#define flush() fwrite(obuf, O - obuf, 1, stdout);
int length;
char none[1 << 23], buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &x){x = 0;T f = 1;char ch = getch();while (!isdigit(ch))f = (ch == '-') ? -1 : f,ch = getch();while (isdigit(ch))x = x * 10 + (ch ^ 48), ch = getch();x *= f;}
template<typename T, typename... Args>inline void read(T& t, Args&... args){read(t);read(args...);}
template<typename T>inline void print(T x, char text = '\n'){clear(none);length = 0;do{none[++length] = x % 10 + 48;}while(x/=10);for (int i = length; i >= 1; --i)*O++ = none[i];*O++ = text;}
struct cas
{
    int v, p, q;
}a[maxm], r[maxm][maxm];
int n, m , t[maxm], v[maxm][10], p[maxm][10], cnt[maxm], f[maxn], ans;
void init()
{
	read(n, m);
    for(int i(1); i <= m; ++i)
    {
        read(a[i].v, a[i].p, a[i].q);
        if(a[i].q)
        {
            ++t[a[i].q];
            r[a[i].q][t[a[i].q]].v = a[i].v;
            r[a[i].q][t[a[i].q]].p = a[i].p;
            r[a[i].q][t[a[i].q]].q = a[i].q;
        }
    }
}
void work()
{
	for(int i(1); i <= m; ++i)
    {
        if(t[i])
        {
            memset(f, -1, sizeof f);
            f[0]=0;
            for(int j(1); j <= t[i]; ++j)
                for(int k(n-a[i].v); k >= r[i][j].v; --k)
                    if(f[k] < f[k - r[i][j].v] + r[i][j].v * r[i][j].p && f[k - r[i][j].v] != -1)
                        f[k] = f[k - r[i][j].v] + r[i][j].v * r[i][j].p;
            for(int j(0); j <= n - a[i].v; ++j)
                if(f[j] != -1)
                {
                    ++cnt[i];
                    v[i][cnt[i]] = j + a[i].v;
                    p[i][cnt[i]] = f[j] + a[i].v * a[i].p;
                }
        }
        if(!a[i].q)
        {
            ++cnt[i];
            v[i][cnt[i]] = a[i].v;
            p[i][cnt[i]] = a[i].v * a[i].p;
        }
    }
    clear(f);
    for(int i(1); i <= m; ++i)
        for(int j(n); j >= 0; --j)
            for(int k(1); k <= cnt[i]; ++k)
                if(j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + p[i][k]);
    for(int i(0); i <= n; ++i)ans = max(ans, f[i]);
    print(ans);
	flush();
}
int main()
{
	init();
	work();
}