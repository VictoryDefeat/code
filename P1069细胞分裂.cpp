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
#define maxn 10010
#define mod (1e9 + 7)
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 23, stdin), p1 == p2) ? EOF : *p1++)
#define flush() fwrite(obuf, O - obuf, 1, stdout);
int length;
char none[1 << 23], buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &x){x = 0;T f = 1;char ch = getch();while (!isdigit(ch))f = (ch == '-') ? -1 : f,ch = getch();while (isdigit(ch))x = x * 10 + (ch ^ 48), ch = getch();x *= f;}
template<typename T, typename... Args>inline void read(T& t, Args&... args){read(t);read(args...);}
template<typename T>inline void print(T x, char text = '\n'){clear(none);length = 0;if(x < 0)x = -x, *O++ = '-';do{none[++length] = x % 10 + 48;}while(x/=10);for (int i = length; i >= 1; --i)*O++ = none[i];*O++ = text;}
int n, m1, m2, s[maxn], prime[maxn], len, t = 2, c, ans = INF, l;
void init()
{
	read(n, m1, m2);
    for(int i = 1; i <= n; ++i)read(s[i]);
}
void work()
{
	if(m1 == 1){print(0);flush();return;}
    while(m1 != 1)
    {
        while(!(m1 % t))m1 /= t, ++prime[t];
        len = max(len, t);
        prime[t++] *= m2;
	}
    for(int i = 1; i <= n; ++i)
    {
        l = 0;
        for(int j = 2; j <= len; ++j)
        {
            if(!prime[j])continue;
            c = 0;
            while(!(s[i] % j))s[i] /= j, ++c;
            if(!c){l = INF;break;}
            l = max(l, (prime[j] - 1) / c);
        }
        ans = min(ans,l);
    }
    print(ans == INF ? -1 : ans + 1);
	flush();
}
int main()
{
	init();
	work();
}