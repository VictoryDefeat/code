#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b;
string x;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        cin>>x;
        scanf("%d%d",&a,&b);
        if(a>=2400&&b>a)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
