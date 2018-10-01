//poj 2559
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int w[MAXN];
int stk[MAXN];
int top;
int main(){
    int n;
    while(scanf("%d",&n),n){
        ll ans=0;
        top=0;
        stk[top]=0;
        for(int i=1;i<=n+1;i++){
            if(i<=n)scanf("%d",&a[i]);
            else a[i]=0;
            if(a[i]>a[stk[top]]){
                stk[++top]=i;
                w[top]=1;
            }else{
                int width=0;
                while(a[i]<a[stk[top]]){
                    width+=w[top];
                    ans=max(ans,1LL*a[stk[top]]*width);
                    top--;
                }
                stk[++top]=i;
                w[top]=width+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
