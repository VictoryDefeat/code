#include<cstdio>
int n,a[10000],sum,h,t,x,s,z;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int i=1;
    while(a[i]==0)++i;
    while(i<n)
    {
        h=-1;
        s=i;
        x=a[i];
        t=i+1;
        if(a[t]>=x)
        {
            ++i;
            continue;
        }
        i+=2;
        while(i<n)
        {
            if(a[i]>a[t])
            {
                t=i;
                if(a[i]>=x)
                {
                    h=x;
                    break;
                }
            }
            ++i;
        }
        if(t==s+1)break;
        else
        {
            if(h==-1)
            {
                h=a[t];
                i=t;
            }
            for(int j=s+1;j<t;++j)
                sum+=h-a[j];
        }
    }
    printf("%d",sum);
}
