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
int A[MAXN];
int es[MAXN*2],qid[MAXN*2],fst[MAXN],nxt[MAXN*2];
int coe;
int ans[MAXN];
int num[MAXN];
vector<int> V[MAXN];

inline void mkedg(int u,int v,int id)
{
    es[++coe]=v;
    qid[coe]=id;
    nxt[coe]=fst[u];
    fst[u]=coe;
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
        A[0]=0;
        for (int i=1;i<=N;++i)
            scanf("%d",&A[i]);
        scanf("%d",&QQ);
        int L,R,X;
        coe=1; MEM0(fst);
        for (int i=1;i<=QQ;++i)
        {
            scanf("%d%d%d",&L,&R,&X);
            mkedg(L-1,X,i);
            mkedg(R,X,i);
        }
        MEM0(num);
        MEM(ans,-1);
        for (int i=0;i<=N;++i)
        {
            ++num[A[i]];
            for (int k=fst[i];k;k=nxt[k])
            {
                int v=es[k],res=num[1];
                for (int j=0;j<V[v].size();++j)
                    res+=num[V[v][j]];
                if (ans[qid[k]]==-1) // before left node
                    ans[qid[k]]=res;
                else // before right node
                    ans[qid[k]]=res-ans[qid[k]];
            }
        }
        for (int i=1;i<=QQ;++i)
            printf("%d\n",ans[i]);
    }

    return 0;
}