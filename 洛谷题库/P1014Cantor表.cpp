#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int cen=1,n;
    cin>>n;
    while(n>cen){
        n-=cen;
        cen++;
    }
    if(cen%2==1){
        cout<<cen-n+1<<"/"<<n;
    }
    if(cen%2==0){
        cout<<n<<'/'<<cen-n+1;
    }
    return 0;
}
