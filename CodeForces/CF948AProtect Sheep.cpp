#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
char a[1000][1000];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='W')
                if(a[i+1][j]=='S'||a[i-1][j]=='S'||a[i][j+1]=='S'||a[i][j-1]=='S')
                {
                    puts("NO");
                    return 0;
                }
    puts("YES");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.')cout<<'D';
            else cout<<a[i][j];
        cout<<endl;
    }
}
