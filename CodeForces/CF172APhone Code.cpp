#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF=2147483647;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
int n,len;
char s[100000][30];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]);
}
bool check(int i)
{
	for(int k=2;k<=n;++k)
		if(s[k][i]!=s[k-1][i])
			return 1;
	return 0;
}
void work()
{
	int k=0;
	len=strlen(s[1]);
	for(;k<len;++k)
		if(check(k)==1)
			break;
	printf("%d",k);
}
int main()
{
	init();
	work();
}