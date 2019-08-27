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
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 21, stdin), p1 == p2) ? EOF : *p1++)
#define flush() fwrite(obuf, O - obuf, 1, stdout);
int length;
char none[1 << 23], buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &x){x = 0;T f = 1;char ch = getch();while (!isdigit(ch))f = (ch == '-') ? -1 : f,ch = getch();while (isdigit(ch))x = x * 10 + (ch ^ 48), ch = getch();x *= f;}
template<typename T, typename... Args>inline void read(T& t, Args&... args){read(t);read(args...);}
template<typename T>inline void print(T x, char text = '\n'){clear(none);length = 0;do{none[++length] = x % 10 + 48;}while(x/=10);for (int i = length; i >= 1; --i)*O++ = none[i];*O++ = text;}
int n, a[maxn], f[maxn][maxn], ans = -1;
void init()
{
	read(n);
	for (int i = 1; i <= n; ++i)read(a[i]),a[i+n]=a[i];
}
void work()
{
	for (int i = 2; i < n << 1; ++i)
        for (int j = i - 1; i - j < n && j >= 1; --j)
        {
            for(int k = j; k < i; ++k)
            	f[j][i] = max(f[j][i], f[j][k] + f[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
            if(f[j][i] > ans)ans = f[j][i];
        }
    print(ans);
    flush();
}
int main()
{
	init();
	work();
}