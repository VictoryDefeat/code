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
#define maxn 100010
#define mul(a) a * a
#define cube(a) a * a * a
int ans[1000000];
int cnt(int n)
{
    int sm = 0;
    while(n % 10 == 0)
    {
        ++sm;
        n /= 10;         
    }
    return sm;
}
int n, m, a[101], b = 2, c[5000], sum, j, now = 1, id = 1, newn, k;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i)scanf("%d", &c[i]);
    for(int i = 0; i <= 99; ++i)a[i] = 0;
    for(int i = 1; i <= n + 99; ++i)
    {
        newn = b - 99;
        if(newn > now)
        {
            k = id;
            for(j = id; j <= newn - now + id; ++j)
            {
                if(k == 101)
                    k = 1;
                if(a[k] == 0 && j - id + now <= n)
                {
                    ans[sum] = j - id + now;
                    ++sum;
                }
                ++k;
            }
            k = id;
            for(j = id; j <= b - 99 - now + id; ++j)
            {
                if(k == 101)
                    k = 1;
                a[k] = 0;
                ++k;
            }
            now = j - id + now;
            if(k == 101)
                id = 1;
            else
                id = k;
        }
        if(b - now + id < 101)
            a[b - now + id] = 1;
        else if((b - now + id) % 101 + 1 == 101)
            a[1] = 1;
        else
            a[(b - now + id) % 101 + 1] = 1;
        b = b + 2 - 9 * cnt(i + 1);
    }
    printf("%d\n", sum);
    for(int i = 0; i < m; ++i)
        printf("%d ", ans[c[i]-1]);
    return 0;
}
