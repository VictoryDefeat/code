#include<cstdio>
double x,l,r,mid,a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}
int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(x=-100;x<=100;x++)
    {
        if(f(x)==0)printf("%.2lf ",x);
        else if(f(x)*f(x+1)<0)
        {
            l=x;r=x+1;
            while(l+0.001<=r)
            {
                mid=(r+l)/2;
                if(f(l)*f(mid)<=0)r=mid;
                else l=mid;
            }
            printf("%.2lf ",l);
        }
    }
}
