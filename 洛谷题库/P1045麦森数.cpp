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
long long a[5000]={0},b,c[50000]={0};
void multi(long long a[],long long b[])
{
    int c[100000] = {0};
    c[0] = a[0] + b[0];
    if (c[0] > 500)c[0] = 500;
    for (int i = 0; i < b[0]; ++i)
        for (int q = 0; q < a[0]; ++q)
        {
            c[i + q + 1] += a[q + 1] * b[i + 1];
            if(c[i + q + 1]>=10)
            {
                c[i + q +2] += c[i + q + 1] / 10;
                c[i + q + 1] %= 10;
            }
        }
    for (int i = 0; i <= c[0]; ++i)a[i] = c[i];
}
void out(long long a[])
{
    int q = 500;
    for(int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            cout << a[q];
            --q;
        }
        cout << endl;
    }
}
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	a[0] = a[1] = c[0] = 1;c[1] = 2;
    cin >> b;
}
void work()
{
    int k = 0.30103 * b + 1;
    cout << k << endl;
    if (b & 1)multi(a,c);
    b >>= 1;
    while (b)
    {
        multi(c,c);
        if (b & 1)multi(a,c);
        b >>= 1;
	}
    --a[1];
    out(a);
}
int main()
{
	init();
	work();
}