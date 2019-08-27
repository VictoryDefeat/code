#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int>q;
int n,a,b,x;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)scanf("%d",&x),q.push(x);
	int t=a,k=q.top();
	q.pop();
	k-=b;
	q.push(k);
	while(1)
	{
		k=q.top();
		q.pop();
		if(k-t<=0){printf("%d",t/a);return 0;}
		k-=b;
		q.push(k);
		t+=a;
	}
}
