#include<cstdio>
int n,a=-1,b=-1;
char s[200];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;++i)
        if(s[i]=='1')
        {
            if(a==-1)a=i;
            else if(b==-1)b=i-a;
            else if(b!=(i-a))
            {
                puts("NO");
                return 0;
            }
            a=i;
        }
    puts("YES");
}
