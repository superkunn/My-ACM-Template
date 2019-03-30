#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define lch(x) tr[x].son[0]
#define rch(x) tr[x].son[1]
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
const int MAXN=100+10;
double EPS=1e-10;
double add(double a,double b){
    if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0;
    else return a+b;
}
struct P{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator + (P p){
        return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p){
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator * (double d){
        return P(x*d,y*d);
    }
    double dot(P p){//内积
        return add(x*p.x,y*p.y);
    }
    double det(P p){//外积
        return add(x*p.y,-y*p.x);
    }
};
double dis(P a,P b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp_p(const P& a,const P& b){
    if(a.x!=b.x)return a.x<b.x;
    else return a.y<b.y;
}
vector<P> convex_hull(P* ps,int n){
    sort(ps,ps+n,cmp_p);
    int k=0;
    vector<P> qs(n*2);
    rep(i,0,n-1){
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)k--;
        qs[k++]=ps[i];
    }
    int t=k;
    per(i,n-2,0){
        while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0)k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
P ps[MAXN];
int main(){
    int n;
    int kase=0;
    while(scanf("%d",&n),n){
        double ans=1e9;
        rep(i,0,n-1){
            int x,y;
            scanf("%d%d",&x,&y);
            ps[i]=P(x,y);
        }
        vector<P> qs=convex_hull(ps,n);
        n=qs.size();
        qs.pb(qs[0]);
        rep(i,0,n-1){
            double now=0;
            int a=i,b=i+1;
            rep(j,0,n-1){
                if(j==a||j==b)continue;
                if(i==n-1&&j==0)continue;
//                cout<<a<<" "<<b<<" "<<j<<endl;
//                cout<<(qs[a]-qs[j]).det(qs[b]-qs[j])<<endl;
//                cout<<dis(qs[a],qs[b])<<endl;
//                cout<<qs[a].x<<" "<<qs[a].y<<endl;
//                cout<<qs[b].x<<" "<<qs[b].y<<endl;
                now=max(now,abs(((qs[a]-qs[j]).det(qs[b]-qs[j]))/dis(qs[a],qs[b])));
            }
            ans=min(ans,now);
        }
        ans*=100;
        ans=ceil(ans);
        ans/=100;
        printf("Case %d: %.2f\n",++kase,ans);
    }
    return 0;
}
/*
3
0 0
3 0
0 4
4
0 10
10 0
20 10
10 20
0
*/
