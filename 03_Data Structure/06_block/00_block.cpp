//poj 3468
#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=1e5+10;
int L[MAXN],R[MAXN],pos[MAXN];
ll a[MAXN],b[MAXN],c[MAXN];
int t;
void update(int x,int y,int z){
    int l=pos[x];
    int r=pos[y];
    if(l==r){
        for(int i=x;i<=y;i++){
            a[i]+=z;
        }
        b[l]+=1LL*z*(y-x+1);
    }else{
        for(int i=l+1;i<r;i++){
            c[i]+=z;
        }
        for(int i=x;i<=R[l];i++){
            a[i]+=z;
        }
        b[l]+=1LL*z*(R[l]-x+1);
        for(int i=L[r];i<=y;i++){
            a[i]+=z;
        }
        b[r]+=1LL*z*(y-L[r]+1);
    }
}
ll query(int x,int y){
    ll res=0;
    int l=pos[x];
    int r=pos[y];
    if(l==r){
        for(int i=x;i<=y;i++){
            res+=a[i];
        }
        res+=c[l]*(y-x+1);
    }else{
        for(int i=l+1;i<r;i++){
            res+=c[i]*(R[i]-L[i]+1)+b[i];
        }
        for(int i=x;i<=R[l];i++){
            res+=a[i];
        }
        res+=c[l]*(R[l]-x+1);
        for(int i=L[r];i<=y;i++){
            res+=a[i];
        }
        res+=c[r]*(y-L[r]+1);
    }
    return res;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    t=sqrt(n);
    for(int i=1;i<=t;i++){
        L[i]=(i-1)*t+1;
        R[i]=i*t;
    }
    if(R[t]<n){
        t++;
        L[t]=R[t-1]+1;
        R[t]=n;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=t;i++){
        for(int j=L[i];j<=R[i];j++){
            pos[j]=i;
            b[i]+=a[j];
        }
    }
    char op[5];
    while(q--){
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='Q'){
            printf("%lld\n",query(x,y));
        }else{
            int z;
            scanf("%d",&z);
            update(x,y,z);
        }
    }
    return 0;
}
