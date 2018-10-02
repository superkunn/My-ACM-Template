#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3e5+10;
ll sum[MAXN];
int que[MAXN];
int st,ed;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    sum[0]=0;
    st=ed=0;
    que[ed++]=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&sum[i]);
        sum[i]+=sum[i-1];
        while(i-que[st]>m){
            st++;
        }
        ans=max(ans,sum[i]-sum[que[st]]);
        while(st!=ed&&sum[que[ed-1]]>=sum[i]){
            ed--;
        }
        que[ed++]=i;
    }
    printf("%lld",ans);
    return 0;
}
