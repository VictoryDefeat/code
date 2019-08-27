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
#define maxn 110
#define mod (1e9 + 7)
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 23, stdin), p1 == p2) ? EOF : *p1++)
#define flush() fwrite(obuf, O - obuf, 1, stdout);
int length;
char none[1 << 23], buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &x){x = 0;T f = 1;char ch = getch();while (!isdigit(ch))f = (ch == '-') ? -1 : f,ch = getch();while (isdigit(ch))x = x * 10 + (ch ^ 48), ch = getch();x *= f;}
template<typename T, typename... Args>inline void read(T& t, Args&... args){read(t);read(args...);}
template<typename T>inline void print(T x, char text = '\n'){clear(none);length = 0;if(x < 0)x = -x, *O++ = '-';do{none[++length] = x % 10 + 48;}while(x/=10);for (int i = length; i >= 1; --i)*O++ = none[i];*O++ = text;}
int m, n, a[maxn][maxn], f[maxn << 1][maxn][maxn], ans;
void init()
{
	read(m, n);
  	for(int i = 1; i <= m; ++i)
    	for(int j = 1; j <= n; ++j)
      		read(a[i][j]);
}
void work()
{
	memset(f, -1, sizeof f);
  	f[2][1][1] = 0;
  	for(int k = 3; k < m + n; ++k)
    	for(int i = 1; i < n; ++i)
      		for(int j = i + 1; j <= n; ++j)
      		{
  		      	int s = f[k][i][j];
        		if(f[k - 1][i][j] > s)s = f[k - 1][i][j];
		        if(f[k - 1][i - 1][j] > s)s = f[k - 1][i - 1][j];
    	    	if(f[k - 1][i][j - 1] > s)s = f[k - 1][i][j - 1];
    	    	if(f[k - 1][i - 1][j - 1] > s)s = f[k - 1][i - 1][j - 1];
        		if(s == -1)continue;
		        f[k][i][j] = s + a[k - i][i] + a[k - j][j];
	      	}
  	ans = f[m + n - 1][n - 1][n];
	print(ans);
	flush();
}
int main()
{
	init();
	work();
}