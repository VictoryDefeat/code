#include<cstdio>
int n,a[200],b[200];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j&&a[i]+b[i]==a[j]&&a[j]+b[j]==a[i])
            {
                printf("YES");
                return 0;
            }
    printf("NO");
}
