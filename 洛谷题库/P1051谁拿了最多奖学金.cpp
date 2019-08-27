#include<cstdio>
struct stu
{
    int examscore,talkscore,programs,totalmoney;
    char name[30],isworker,iswest;
}a[110];
int main()
{
    int n,maid=0,ans=0;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)scanf("%s %d %d %c %c %d\n",&a[i].name,&a[i].examscore,&a[i].talkscore,&a[i].isworker,&a[i].iswest,&a[i].programs);
    for(int i=1;i<=n;i++)
    {
        if(a[i].examscore>80&&a[i].programs)a[i].totalmoney+=8000;
        if(a[i].examscore>85&&a[i].talkscore>80)a[i].totalmoney+=4000;
        if(a[i].examscore>90)a[i].totalmoney+=2000;
        if(a[i].examscore>85&&a[i].iswest=='Y')a[i].totalmoney+=1000;
        if(a[i].talkscore>80&&a[i].isworker=='Y')a[i].totalmoney+=850;
        if(a[i].totalmoney>a[maid].totalmoney)maid=i;
        ans+=a[i].totalmoney;
    }
    printf("%s\n%d\n%d",a[maid].name,a[maid].totalmoney,ans);
}
