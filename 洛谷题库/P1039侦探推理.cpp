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
#define maxn 30
#define maxm 200
#define mod (1e9 + 7)
#define getch() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1 ,1 << 23, stdin), p1 == p2) ? EOF : *p1++)
#define flush() fwrite(obuf, O - obuf, 1, stdout);
int length;
char none[1 << 23], buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
template<typename T>inline void read(T &x){x = 0;T f = 1;char ch = getch();while (!isdigit(ch))f = (ch == '-') ? -1 : f,ch = getch();while (isdigit(ch))x = x * 10 + (ch ^ 48), ch = getch();x *= f;}
template<typename T, typename... Args>inline void read(T& t, Args&... args){read(t);read(args...);}
template<typename T>inline void print(T x, char text = '\n'){clear(none);length = 0;do{none[++length] = x % 10 + 48;}while(x/=10);for (int i = length; i >= 1; --i)*O++ = none[i];*O++ = text;}
int n, m, p, wrong[maxm], err, w[maxm], ans;
string name[maxm], say[maxm];
string day[maxm]={" ", "Today is Sunday.", "Today is Monday.", "Today is Tuesday.", "Today is Wednesday.", "Today is Thursday.", "Today is Friday.", "Today is Saturday.",};
void f(int now, int x)
{
    if(wrong[now] && wrong[now] != x)err = 1;
    else wrong[now] = x;
}
void init()
{
	cin >> m >> n >> p;
    for(int i = 1; i <= m; ++i)cin >> name[i];
    for(int i = 1; i <= p; ++i)
    {
        string words;
        cin >> words;
        words.erase(words.end() - 1);
        for(int j = 1; j <= m; ++j)if(name[j] == words)w[i] = j;
        getline(cin, say[i]);
        say[i].erase(say[i].begin());
        say[i].erase(say[i].end()-1);
    }
}
void work()
{
	for(int date = 1; date <= 7; ++date)
    	for(int pri = 1; pri <= m; ++pri)
    	{
    	    err = 0;
    	    clear(wrong);
    	    for(int i = 1; i <= p; ++i)
    	    {
   		        int now = w[i];
    	        if(say[i] == "I am guilty.")f(now, pri == now ? 1 : -1);
    	        if(say[i] == "I am not guilty.")f(now, pri != now ?1 : -1);
    	        for(int j = 1; j <= 7; ++j)if(say[i] == day[j])f(now, j == date ? 1 : -1);
     	        for(int j = 1; j <= m; ++j)
    	        {
    	            if(say[i] == name[j] + " is guilty.")f(now, j == pri ? 1 : -1);
       		        if(say[i] == name[j] + " is not guilty.")f(now, j != pri ? 1 : -1);
        	    }
    	    }
        	int sum = 0,unknown = 0;
        	for(int i = 1; i <= m; ++i)
	        {
    	        if(wrong[i] == -1)++sum;
        	    if(wrong[i] == 0)++unknown;
	        }
    	    if(!err && sum <= n && sum + unknown >= n)
        	    if(ans && ans != pri)
            	{
                	cout << "Cannot Determine";
	                return;
    	        }
        	    else ans = pri;
	    }
    if(!ans)cout << "Impossible"; 
    else cout << name[ans];
}
int main()
{
	init();
	work();
}