#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=200010;
int n,m,cnt,root;
int a[N];
char c;
struct node
{
    int l,r,sum;
}tree[N<<2];
void build(int &now,int l,int r)
{
    if(now==0)now=++cnt;
    if(l==r)
	{
        tree[now].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(tree[now].l,l,mid);
    build(tree[now].r,mid+1,r);
    tree[now].sum=max(tree[tree[now].l].sum,tree[tree[now].r].sum);
}
void insert(int &now,int l,int r,int x,int k)
{
    if(now==0)now=++cnt;
    if(l==r)
	{
        tree[now].sum=max(tree[now].sum,k);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)insert(tree[now].l,l,mid,x,k);
    else insert(tree[now].r,mid+1,r,x,k);
    tree[now].sum=max(tree[tree[now].l].sum,tree[tree[now].r].sum);
}
int query(int now,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return tree[now].sum;
    int mid=(l+r)>>1,maxl=0,maxr=0;
    if(x<=mid)maxl=max(maxl,query(tree[now].l,l,mid,x,y));
    if(y>mid)maxr=max(maxr,query(tree[now].r,mid+1,r,x,y));
    return max(maxl,maxr);
}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    build(root,1,n);
    for(int i=1;i<=m;++i)
	{
        cin>>c;
        if(c=='Q')
		{
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(root,1,n,x,y));
        }
        else
		{
            int x,k;
            scanf("%d%d",&x,&k);
            insert(root,1,n,x,k);
        }
    }
	return 0;
}
