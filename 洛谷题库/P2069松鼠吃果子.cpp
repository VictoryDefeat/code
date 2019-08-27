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
#define maxn 310
#define mul(a) a * a
#define cube(a) a * a * a
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 23, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &aaa){aaa = 0;T fff = 1;char ch = getch();while (!isdigit(ch))fff = (ch == '-') ? -1 : fff,ch = getch();while (isdigit(ch))aaa = aaa * 10 + (ch ^ 48), ch = getch();aaa *= fff;}
template<typename T, typename... Args>inline void read(T& QAQ, Args&... args){read(QAQ);read(args...);}
int n, m, id[maxn], ans = 1;
int main()
{
    read(m, n);
    for(int i = 1; i <= m; ++i)id[i] = i;
    for(int i = 1; i <= n; ++i)
    {
        int tmp = cube(i) % 5 + 1;
        ans += tmp;
        if(ans > m - i + 1)ans = tmp + 1;
        if(i != n)
            for(int j = ans + 1; j <= m - i + 1; ++j)
                id[j - 1] = id[j];
    }
    printf("%d\n", id[ans]);
    return 0;
}
