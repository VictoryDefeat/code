#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
bool need[10];//是否需要宝石
string s,all[10]={"","Power","Space","Reality","Soul","Time","Mind"};//将所有宝石存储下来，此处按灭霸获取宝石的顺序
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s=="purple")need[1]=1;//6种宝石及其颜色的判断
        if(s=="blue")need[2]=1;
        if(s=="red")need[3]=1;
        if(s=="orange")need[4]=1;
        if(s=="green")need[5]=1;
        if(s=="yellow")need[6]=1;
    }
    for(int i=1;i<=6;i++)
        if(!need[i])m++;//统计所需宝石数
    printf("%d\n",m);
    for(int i=1;i<=6;i++)if(!need[i])cout<<all[i]<<endl;//输出需要的宝石
}
/*
借此在这里声明一下：存储顺序及输出顺序是随意的，可以按自己想法输出，无须按我的方法存储
最后声明一下：
抄袭可耻！
抄袭可耻！
抄袭可耻！
*/
