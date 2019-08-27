#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
#define clear(a) memset(a,0,sizeof a)
#define cleam(a) memset(a,0x3f,sizeof a)
#define maxn 300010
#define mod (1e9+7)
int n, r, q, w[maxn];
struct node
{
	int grade, id;
}a[maxn], A[maxn], B[maxn];
bool cmp(node a, node b)
{
	if (a.grade == b.grade)return a.id < b.id;
	return a.grade > b.grade;
}
void init()
{
	cin >> n >> r >> q;
	for (int i = 1; i <= n << 1; ++i)
	{
		cin >> a[i].grade;
		a[i].id = i;
	}
	for (int i = 1; i <= n << 1; ++i)cin >> w[i];
}
void MergeSort()
{
	int i = 1, j = 1, k = 1;
	while (i <= n && j <= n)
	{
		if (A[i].grade > B[j].grade || (A[i].grade == B[j].grade && A[i].id < B[j].id))
		{
			a[k].grade = A[i].grade;
			a[k++].id = A[i++].id;
		}
		else
		{
			a[k].grade = B[j].grade;
			a[k++].id = B[j++].id;
		}
	}
	while (i <= n)
	{
		a[k].grade = A[i].grade;
		a[k++].id = A[i++].id;
	}
	while (j <= n)
	{
		a[k].grade = B[j].grade;
		a[k++].id = B[j++].id;
	}
}
void work()
{
	sort (a + 1, a + 1 + 2 * n, cmp);
	for (int k = 1; k <= r; ++k)
	{
		int now = 1;
		for (int i = 1; i < 2 * n; i += 2)
		{
			if(w[a[i].id] > w[a[i+1].id])
			{
				A[now].grade = a[i].grade+1;
				A[now].id = a[i].id;
				B[now].grade  =  a[i+1].grade;
				B[now].id = a[i+1].id;
				++now;
			}
			else
			{
				A[now].grade = a[i+1].grade+1;
				A[now].id = a[i+1].id;
				B[now].grade  =  a[i].grade;
				B[now].id = a[i].id;
				++now;
			}
		}
		MergeSort();
	}
	cout << a[q].id;
}
int main()
{
	init();
	work();
}