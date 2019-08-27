#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int dx[12]={1,1,-1,-1,2,2,-2,-2,2,2,-2,-2},dy[12]={2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};
bool v[60][60];
struct node
{
    int x,y,sum;
}a,b;
queue<node>q;
int bfs(int x,int y)
{
    node p;
    p.x=x;
    p.y=y;
    p.sum=0;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<12;++i)
        {
            int nx=p.x+dx[i],ny=p.y+dy[i];
            if(nx<1||ny<1||v[nx][ny]==1||nx>50||ny>50)continue;
            node t;
            t.x=nx;
            t.y=ny;
            t.sum=p.sum+1;
            q.push(t);
            v[nx][ny]=1;
            if(nx==1&&ny==1)return t.sum;
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
    printf("%d\n",bfs(a.x,a.y));
    memset(v,0,sizeof(v));
    while(!q.empty())q.pop();
    printf("%d",bfs(b.x,b.y));
}
