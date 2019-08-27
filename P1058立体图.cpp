#include<cstdio>
int m,n,p,a[1010][1010],ma[1010],maxx,maxy,z[10]={2,1,0,0,0,0},s[10]={6,6,6,6,5,4};
char c[1010][1010],c1[20][20]={"  +---+"," /   /|","+---+ |","|   | +","|   |/","+---+"};
void work(int x,int y)
{
    for(int i=5;i>=0;--i)
        for(int j=z[i];j<=s[i];++j)
        {
            c[5-i+x][j+y]=c1[i][j];
            if(5-i+x>maxx)maxx=5-i+x;
            if(j+y>maxy)maxy=j+y;
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&a[i][j]);
    for(int k=1;k<=n;++k)
        for(int i=0;i<m;++i)
            for(int j=0;j<a[k][i];++j)
                work((n-k)*2+1+3*j,(n-k)*2+1+4*i);
    for(int i=maxx;i>=1;--i)
    {
        for(int j=1;j<=maxy;++j)
            if(c[i][j]=='\000')printf(".");
            else printf("%c",c[i][j]);
        printf("\n");
    }
}