#include <cstdio>
void work(int n,int r) {
    if(n==0)return;
    int t=n%r;
    if(t<0)t-=r,n+=r;
    if(t>=10)t=65+t-10;
    else t+=48;
    work(n/r,r);
    printf("%c",t);
}
int main(int argc, char const *argv[]) {
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d=",n);
    work(n,r);
    printf("(base%d)",r);
    return 0;
}
