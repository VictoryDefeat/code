#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a[10]={0},n;
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=i;j>0;j/=10)
			++a[j%10];
	for(int i=0;i<=9;++i)cout<<a[i]<<endl;
}
