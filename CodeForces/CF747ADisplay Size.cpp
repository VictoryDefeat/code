#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=sqrt(n);i>=1;i--)
        for(int j=sqrt(n);j<=n;j++)
            if(i*j==n)
            {
                printf("%d %d",i,j);
                return 0;
            }
}
