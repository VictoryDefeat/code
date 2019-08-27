#include <cstring>
#include <cstdio>
using namespace std;
char isbn[13];
int main(){
    int l=1,s=0;
    for(int i=0;i<12;++i)
    {
        scanf("%c",&isbn[i]);
        if(isbn[i]!='-')s+=(isbn[i]-'0')*l++;
    }
    s%=11;
    char c;
    if(s==10)c='X';
    else c=s+'0';
    char t;
    scanf("%c",&t);
    isbn[12]=t;
    if(t==c) printf("Right");
    else{
        isbn[12]=c;
        printf("%s",isbn);
    }
}
