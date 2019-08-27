#include<cstdio>
int main()
{
    int n,k;
    scanf ("%d",&k);
    double s=1;
    for (n=2;;n++)
    {
        s+=1.0/n;
        if (s>k) {printf ("%d",n);return 0;}
    }
}
