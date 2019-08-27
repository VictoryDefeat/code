#include<cstdio>
int DFS(int n,int m)
{
    if(n==m||m==1)return 1;
    if(n<m)return 0;
    return DFS(n-m,m)+DFS(n-1,m-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",DFS(n,m));
}
