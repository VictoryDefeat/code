#include<cstdio>
#include<cstring>
#define abs(a) (a)<0?-(a):(a)
#define max(a,b) (a)>(b)?(a):(b)
int m,n,high[600][600],f,s[5][360000],sum,dx[5]={1,-1,0,0},dy[5]={0,0,1,-1};
bool visit[600][600];
void dfs(int x,int y,int z)
{
    if(visit[x][y])return;
    visit[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=m&&ny>0&&ny<=n&&abs(high[nx][ny]-high[x][y])<=z)dfs(nx,ny,z);
    }
    return;
}
bool check(int d)
{
    memset(visit,0,sizeof(visit));
    dfs(s[1][1],s[2][1],d);
    for(int i=1;i<=sum;++i)
        if(!visit[s[1][i]][s[2][i]])
            return 0;
    return 1;
}
int main()
{
    int maxx=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            {
                scanf("%d",&high[i][j]);
                maxx=max(maxx,high[i][j]);
            }
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&f);
            if(f)
            {
                s[1][++sum]=i;
                s[2][sum]=j;
            }
        }
    dfs(1,1,21);
    for(int i=1;i<=sum;++i)printf("%d ",visit[s[1][i]][s[2][i]]);
}
/*
int left=-1,right=maxx+10;
while(left+1<right)
{
    int mid=(left+right)/2;
    if(!check(mid))left=mid;
    else right=mid;
}
printf("%d",right);
*/
