#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,t[2000];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d",&a);++t[a];}
	for(int i=1;i<=1000;++i)if(t[i]>1)t[i]=1;
    for(int i=1;i<=998;++i)
        if(t[i]&&t[i+1]&&t[i+2]){printf("YES");return 0;} 
    printf("NO");
}
