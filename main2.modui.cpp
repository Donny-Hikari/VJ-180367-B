#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(_array,val) memset(_array,val,sizeof(_array))
#define MEM0(_array) MEM(_array,0)
#define MEMZ(_array) MEM(_array,0)
#define FORUP(_v,_b,_n) for(int _v=(_b);_v<=(_n);++_v)
#define FORDOWN(_v,_b,_n) for(int _v=(_b);_v>=(_n);--_v)
#define NXTINT(_v) scanf("%d",&(_v))
#define NXTLL(_v) scanf("%lld",&(_v))
#define TCASES() int _T;NXTINT(_T);while (_T--)

const int MAXN=1e5+10;
int N,QQ;
int S;
int A[MAXN];
int part[MAXN];
struct Quest
{
    int L,R,X;
    int id;
    bool operator<(const Quest& o) const
    {
        return part[L]<part[o.L]||
        (part[L]==part[o.L] && R<o.R);
    }
} Q[MAXN];
int ans[MAXN];
vector<int> V[MAXN];
int sum[MAXN];

void add(int p,int v)
{
    sum[A[p]]+=v;
}

int main()
{
#ifdef LOCAL
    freopen("IN.txt","r",stdin);
#endif

    for (int i=2;i<MAXN;++i)
    for (int j=i;j<MAXN;j+=i)
        V[j].push_back(i);
    while (~scanf("%d",&N))
    {
        S=sqrt(N+0.5);
        for (int i=1;i<=N;++i)
        {
            part[i]=(i-1)/S;
            scanf("%d",&A[i]);
        }
        scanf("%d",&QQ);
        for (int i=1;i<=QQ;++i)
        {
            scanf("%d%d%d",&Q[i].L,&Q[i].R,&Q[i].X);
            Q[i].id=i;
        }
        sort(Q+1,Q+1+QQ);
        int l=0,r=0;
        MEM0(sum);
        for (int i=1;i<=QQ;++i)
        {
            for (;l<Q[i].L;++l) add(l,-1);
            for (;l>Q[i].L;--l) add(l-1,1);
            for (;r<Q[i].R;++r) add(r+1,1);
            for (;r>Q[i].R;--r) add(r,-1);
            int res=sum[1];
            for (int j=0;j<V[Q[i].X].size();++j)
                res+=sum[V[Q[i].X][j]];
            ans[Q[i].id]=res;
        }
        for (int i=1;i<=QQ;++i)
            printf("%d\n",ans[i]);
    }

    return 0;
}
