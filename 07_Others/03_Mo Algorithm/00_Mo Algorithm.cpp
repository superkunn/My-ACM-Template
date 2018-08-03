// ---
// 莫队算法,可以解决一类静态,离线区间查询问题。分成 $\sqrt{x}$ 块,分块排序。
// ---
//cf 671 E
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1<<20;
struct node{
    int l,r,id;
}Q[MAXN];
int n,m,k;
int block;
int a[MAXN];
int pre[MAXN];
ll cnt[MAXN];
ll ANS,ans[MAXN];
bool cmp(node x,node y){
    if(x.l/block==y.l/block)return x.r<y.r;
    else return x.l/block<y.l/block;
}
void add(int x){
    ANS+=cnt[pre[x]^k];
    cnt[pre[x]]++;
}
void del(int x){
    cnt[pre[x]]--;
    ANS-=cnt[pre[x]^k];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    block=(int)sqrt(n);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=a[i]^pre[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    ANS=0;
    memset(cnt,0,sizeof(cnt));
    cnt[0]=1;
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(L>Q[i].l){L--;add(L-1);};
        while(L<Q[i].l){del(L-1);L++;}
        while(R<Q[i].r){R++;add(R);};
        while(R>Q[i].r){del(R);R--;};
        ans[Q[i].id]=ANS;
    }
    for(int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
