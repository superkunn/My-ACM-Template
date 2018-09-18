//cf 1042d
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
tree<pair<ll,int>,null_type,less<pair<ll,int> >,rb_tree_tag,tree_order_statistics_node_update > rbt;
int main(){
    int n;
    ll t;
    scanf("%d%I64d",&n,&t);
    rbt.insert({0,0});
    ll now=0,ans=0;
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%I64d",&x);
        now+=x;
        ans+=i-rbt.order_of_key({now-t,n+1});
        rbt.insert({now,i});
    }
    printf("%I64d",ans);
    return 0;
}
