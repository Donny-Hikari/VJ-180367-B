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

const int MAXN=1e5;
int N,M;
LL seg[MAXN*4];
int A[MAXN];

int gcd(LL a,LL b)
{
    if (a>b) swap(a,b);
    int r;
    while (a)
    {
        r=b%a;
        b=a;
        a=r;
    }
    return b;
}
void build(int *Ini,int o,int l,int r)
{
    if (l==r) seg[o]=Ini[l];
    else
    {
        int m=(l+r)>>1;
        build(Ini,2*o,l,m);
        build(Ini,2*o+1,m+1,r);
        seg[o]=seg[2*o]*seg[2*o+1]/gcd(seg[2*o],seg[2*o+1]);
    }
}
int query(int L,int R,int v,int o,int l,int r)
{
    if (l==r) return v%seg[o]==0;
    if (L<=l&&R>=r)
    {
        if (gcd(v,seg[o])==1) return 0;
    }
    int cnt=0;
    int m=(l+r)>>1;
    if (L<=m) cnt=query(L,R,v,2*o,l,m);
    if (R>m) cnt+=query(L,R,v,2*o+1,m+1,r);
    return cnt;
}

int main()
{
#ifdef LOCAL
    //freopen("IN.txt","r",stdin);
#endif

    while (~scanf("%d",&N))
    {
        for (int i=1;i<=N;++i)
            scanf("%d",&A[i]);
        //build(A,1,1,N);
        scanf("%d",&M);
        for (int i=1;i<=M;++i)
        {
            int L,R,X;
            scanf("%d%d%d",&L,&R,&X);
            int cnt=0;
            for (int j=L;j<=R;++j)
            {
                if (X%A[j]==0) ++cnt;
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}
