#include<cstdio>
int main()
{
    int a[11],h,s=0;
    scanf ("%d%d%d%d%d%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10],&h);
    h+=30;
    if (h>=a[1]) s++;
    if (h>=a[2]) s++;
    if (h>=a[3]) s++;
    if (h>=a[4]) s++;
    if (h>=a[5]) s++;
    if (h>=a[6]) s++;
    if (h>=a[7]) s++;
    if (h>=a[8]) s++;
    if (h>=a[9]) s++;
    if (h>=a[10]) s++;
    printf ("%d",s);
}
