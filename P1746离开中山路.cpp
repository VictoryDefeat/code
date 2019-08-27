#include<cstdio>
#include<queue>
using namespace std;
int n,sx,sy,ex,ey,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},s[2000][2000];
bool f[2000][2000];
struct node
{
    int x,y;
}tmp,z;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%1d",&f[i][j]);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    queue<node>q;
    tmp.x=sx;
    tmp.y=sy;
    s[sx][sy]=0;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=tmp.x+dx[i],ny=tmp.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>n||s[nx][ny]!=0||f[nx][ny])continue;
            s[nx][ny]=s[tmp.x][tmp.y]+1;
            z.x=nx;
            z.y=ny;
            q.push(z);
        }
    }
    printf("%d",f[ex][ey]);
}
