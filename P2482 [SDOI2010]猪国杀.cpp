#include<bits/stdc++.h>
using namespace std;
const bool diff[3][3]={{0,0,1},{0,0,1},{1,1,0}};
const int M=2005;
int n,m,sumf,deadf,rounds,t[M],turn[M];
char ch,cu;
struct node
{
	int id,blood,fo,dead,nxt,zg,cnt;
	char cards[M];
}a[15];
deque<char>card;
inline char read()
{
    ch=getchar();
    while(ch<'A'||ch>'Z')ch=getchar();
    return ch;
}
void get(int tmp)
{
    a[tmp].cards[++a[tmp].cnt]=card.front();
    if(card.size()>1)card.pop_front();
}
bool oug(int tmp)
{
    int nxt=a[tmp].nxt;
    if(a[nxt].fo==0)return 0;
	else if(a[nxt].fo==1)return diff[a[tmp].id][a[nxt].id];
    else return a[tmp].id==0;
}
int fi(int tmp)
{
    if(a[tmp].id==2)return 1;
    for(int nxt=a[tmp].nxt;nxt!=tmp;nxt=a[nxt].nxt)
		if(!a[nxt].dead)
        	if((a[nxt].id==2&&a[nxt].fo==1)||(a[tmp].id==0&&a[nxt].fo==-1))return nxt;
    return -1;
}
void isdead(int x,int y)
{
    if(a[x].id==0&&a[y].id==1)
	{
        for(int i=1;i<=a[x].cnt;++i)turn[i]=rounds;a[x].zg=0;
    }
    else if(a[y].id==2)get(x),get(x),get(x);
}
int find(int tmp,char cnt)
{
    for(int i=1;i<=a[tmp].cnt;++i)if(a[tmp].cards[i]==cnt)return i;
    return 0;
}
void cof(int tmp,int s,int t)
{
    for(int i=s;i<t;++i)a[tmp].cards[i]=a[tmp].cards[i+1];
}
void checkp(int tmp,int x)
{
    int re=find(tmp,'P');
    if(tmp==x)
	{
        re=0;
        for(int i=1;i<=a[tmp].cnt;++i)if(turn[i]!=rounds&&a[tmp].cards[i]=='P'){re=i;break;}
        if(re)turn[re]=rounds,++a[tmp].blood;
        return;
    }
    if(re)++a[tmp].blood,cof(tmp,re,a[tmp].cnt),--a[tmp].cnt;
}
bool checkd(int tmp)
{
    int re=find(tmp,'D');
    if(re)cof(tmp,re,a[tmp].cnt),--a[tmp].cnt;
    return re;
}
bool checkk(int tmp,int x)
{
    int re=find(tmp,'K');
    if(tmp==x)
	{
        re=0;
        for(int i=1;i<=a[tmp].cnt;++i)if(turn[i]!=rounds&&a[tmp].cards[i]=='K'){re=i;break;}
        if(re)turn[re]=rounds;
        return re;
    }
    if(re)cof(tmp,re,a[tmp].cnt),a[tmp].cnt--;
    return re;
}
bool checkj(int tmp,int x)
{
    int re=find(tmp,'J');
    if(tmp==x)
	{
        re=0;
        for(int i=1;i<=a[tmp].cnt;++i)if(turn[i]!=rounds&&a[tmp].cards[i]=='J'){re=i;break;}
        if(re)turn[re]=rounds;
        return re;
    }
    if(re)cof(tmp,re,a[tmp].cnt),--a[tmp].cnt;
    return re;
}
void blood(int tmp,int x)
{
    --a[tmp].blood;if(a[tmp].blood<1)checkp(tmp,x);
}
void link(int tmp)
{
    for(int pre=1;pre<=n;++pre)
        if(!a[pre].dead&&a[pre].nxt==tmp){a[pre].nxt=a[tmp].nxt;break;}
}
void usep(int tmp)
{
    ++a[tmp].blood;
}
void usek(int tmp)
{
    int nxt=a[tmp].nxt;
    a[tmp].fo=1;
    if(!checkd(nxt))
	{
        blood(nxt,tmp);
        if(a[nxt].blood<1)deadf+=(a[nxt].id==2),a[nxt].dead=1,a[tmp].nxt=a[nxt].nxt;
        if(sumf==deadf||a[1].dead)return;
        if(a[nxt].blood<1)isdead(tmp,nxt);
    }
}
bool usej(int x,int tmp,int cnt,int now)
{
    bool ret=now;
    for(int nxt=tmp;;)
		if(!a[nxt].dead)
		{
        	if(!now)
			{
            	if(!diff[a[nxt].id][a[cnt].id])
	                if(checkj(nxt,x)){a[nxt].fo=1;return usej(x,nxt,cnt,1-now);}
    	    }else
			{
        	    if(diff[a[nxt].id][a[cnt].id])
            	    if(checkj(nxt,x)){a[nxt].fo=1;return usej(x,nxt,cnt,1-now);}
        	}
        	nxt=a[nxt].nxt;
			if(nxt==tmp)break;
    	}
    return ret;
}
void usef(int tmp,int cnt,int x)
{
    a[tmp].fo=1;
    if (a[cnt].fo==1)
	{
        if(usej(tmp,tmp,cnt,0))return;
    }
    for(;;)
	{
        if(a[tmp].id==0&&a[cnt].id==1)
		{
            blood(cnt,x);
            if(a[cnt].blood<1)deadf+=(a[cnt].id==2),a[cnt].dead=1,link(cnt);
            if(sumf==deadf||a[1].dead)return;
            if(a[cnt].blood<1)isdead(tmp,cnt);
            return;
        }
        else if(!checkk(cnt,x))
		{
            blood(cnt,x);
            if(a[cnt].blood<1)deadf+=(a[cnt].id==2),a[cnt].dead=1,link(cnt);
            if(sumf==deadf||a[1].dead)return;
            if(a[cnt].blood<1)isdead(tmp,cnt);
            return;
        }
        if(!checkk(tmp,x))
		{
            blood(tmp,x);
            if(a[tmp].blood<1)deadf+=(a[tmp].id==2),a[tmp].dead=1,link(tmp);
            if(sumf==deadf||a[1].dead)return;
            if(a[tmp].blood<1)isdead(cnt,tmp);
            return;
        }
    }
}
void usen(int tmp)
{
    for(int nxt=a[tmp].nxt;nxt!=tmp;nxt=a[nxt].nxt)if(!a[nxt].dead)
	{
        if(a[nxt].fo==1)
            if(usej(tmp,tmp,nxt,0))continue;
        if(!checkk(nxt,tmp))
		{
            blood(nxt,tmp);if(nxt==1&&a[tmp].fo==0)a[tmp].fo=-1;
            if(a[nxt].blood<1)deadf+=(a[nxt].id==2),a[nxt].dead=1,link(nxt);
            if(sumf==deadf||a[1].dead)return;
            if(a[nxt].blood<1)isdead(tmp,nxt);
        }
    }
}
void usew(int tmp)
{
    for(int nxt=a[tmp].nxt;nxt!=tmp;nxt=a[nxt].nxt)if(!a[nxt].dead)
	{
        if(a[nxt].fo==1)
            if(usej(tmp,tmp,nxt,0))continue;
        if(!checkd(nxt))
		{
            blood(nxt,tmp);if(nxt==1&&a[tmp].fo==0)a[tmp].fo=-1;
            if(a[nxt].blood<1)deadf+=(a[nxt].id==2),a[nxt].dead=1,link(nxt);
            if(sumf==deadf||a[1].dead)return;
            if(a[nxt].blood<1)isdead(tmp,nxt);
        }
    }
}
void usez(int tmp)
{
    a[tmp].zg=1;
}
bool dis(int tmp)
{
    memset(turn,0,sizeof turn);
    int cntused,totkill=0,counts,ret=-1,cnt;
	char now;
    for(rounds=1;;++rounds)
	{
        cntused=counts=0;
        for(int i=1;i<=a[tmp].cnt;i++)if(turn[i]!=rounds)
		{
            now=a[tmp].cards[i];
            switch(now)
			{
                case 'P':
                    if(a[tmp].blood<4)usep(tmp),turn[i]=rounds,++cntused,i=a[tmp].cnt;
                    break;
                case 'K':
                    if((!totkill||a[tmp].zg)&&oug(tmp))usek(tmp),turn[i]=rounds,++cntused,++totkill,i=a[tmp].cnt;
                    break;
                case 'F':
                    cnt=fi(tmp);if(cnt!=-1)usef(tmp,cnt,tmp),turn[i]=rounds,++cntused,i=a[tmp].cnt;
                    break;
                case 'N':
                    usen(tmp),turn[i]=rounds,++cntused,i=a[tmp].cnt;
                    break;
                case 'W':
                    usew(tmp),turn[i]=rounds,++cntused,i=a[tmp].cnt;
                    break;
                case 'Z':
                    usez(tmp),turn[i]=rounds,++cntused,i=a[tmp].cnt;
                    break;
                default:
                    break;
            }
            if(sumf==deadf||a[1].dead){ret=1;break;}
            if(a[tmp].dead){ret=0;break;}
        }
        for(int i=1;i<=a[tmp].cnt;++i)if(turn[i]!=rounds)t[++counts]=a[tmp].cards[i];
        for(int i=1;i<=counts;++i)a[tmp].cards[i]=t[i];a[tmp].cnt=counts;
        if(!cntused&&ret!=1)ret=0;
        if(ret>-1)return ret;
    }
}
bool round(int tmp)
{
    get(tmp),get(tmp);
    return dis(tmp);
}
int main()
{
    scanf("%d%d",&n,&m),sumf=deadf=0;
    for(int i=1;i<=n;++i)
	{
        a[i].blood=a[i].cnt=4,a[i].dead=a[i].fo=a[i].zg=0,a[i].nxt=i%n+1;
        cu=read(),sumf+=(cu=='F'),a[i].id=(cu!='F')?((cu!='Z')?0:1):2,cu=read();
        for(int j=1;j<=4;++j)a[i].cards[j]=read();
    }
    a[1].fo=1;
    for(int i=1;i<=m;++i)card.push_back(read());
    for(int i=1,finish=0;!finish&&sumf>0;i=a[i].nxt)if(!a[i].dead)finish=round(i);
    printf("%s\n",a[1].dead?"FP":"MP");
    for(int i=1;i<=n;++i)
	{
        if(a[i].dead)printf("%s","DEAD");
		else
		{
            if(a[i].cnt>0)printf("%c",a[i].cards[1]);
            for(int j=2;j<=a[i].cnt;++j)printf(" %c",a[i].cards[j]);
        }
        putchar('\n');
    }
    return 0;
}