#include<cstdio>
int n,l,g,w,h;
int main()
{
    scanf("%d%d%d",&n,&l,&g);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&w,&h);
        if(w<l||h<l){printf("Too Young\n");continue;}
        while(w>g||h>g)
        {
            w>>=1;
            h>>=1;
        }
        if(w<l||h<l){printf("Too Young\n");continue;}
        if(w==h)printf("Sometimes Naive\n");
        else printf("Too Simple\n");
    }
    return 0;
}
