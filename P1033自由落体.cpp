#include<iostream>
#include<cmath>
using namespace std;
int n,ib,ie;
double h,s,v,l,k,tmax,tmin;
int main()
{
    cin>>h>>s>>v>>l>>k>>n;
    tmax=sqrt(h/5),tmin=sqrt((h-k)/5);
    ib=int(s-tmin*v+l),ie=int(s-tmax*v);
    ib=min(ib,n);ie=max(ie,0);
    cout<<ib-ie;
}
