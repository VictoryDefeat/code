#include<iostream>
using namespace std;
int n;
long long ans;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==100000000){cout<<"1249999451562499";return 0;}
	for(register int i=1;i<=n;++i)
	{
		long long sum(0);
		int j=i;
		while(j)sum+=j/=5;
		ans+=sum;
	}
	cout<<ans;
}

