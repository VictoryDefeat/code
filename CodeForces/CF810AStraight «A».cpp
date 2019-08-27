#include<cstdio>
#include<cmath>//使用round必须要调用cmath库
int n,x,sum,k,av;//x为一个变量代替数组（因为本题无需使用数组），av表示平均数，sum表示当前所有数的和
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        sum+=x;
    }//输入并计算初始和
    int n1=n;//记录初始个数
    double t=sum*1.0/n;
    av=round(t);//计算出在不插入k的情况下的平均数，作为特判
    while(av!=k)//只要平均数不为k
    {
        sum+=k;
        ++n;
        t=sum*1.0/n;
        av=round(t);//在序列中插入k，并求出新的平均数
    }
    printf("%d",n-n1);//输出答案，最终个数减去初始个数
}
