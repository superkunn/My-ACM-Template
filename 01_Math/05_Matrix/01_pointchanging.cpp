#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
struct Matrix{
    double a[3][3];
    void init(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]=0;
            }
        }
    }
    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------"<<endl;
    }
};
Matrix operator*(const Matrix& lhs,const Matrix& rhs){
    Matrix res;
    res.init();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                res.a[i][j]+=lhs.a[i][k]*rhs.a[k][j];
            }
        }
    }
    return res;
}
const int MAXN=1e4+10;
double x[MAXN],y[MAXN];
int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    Matrix base;
    base.init();
    base.a[0][0]=base.a[1][1]=base.a[2][2]=1;
    char op[3];
    Matrix now;
    while(m--){
        scanf("%s",op);
        now.init();
        if(op[0]=='X'){
            now.a[0][0]=1;
            now.a[1][1]=-1;
            now.a[2][2]=1;
        }else if(op[0]=='Y'){
            now.a[0][0]=-1;
            now.a[1][1]=1;
            now.a[2][2]=1;
        }else if(op[0]=='M'){
            double p,q;
            scanf("%lf%lf",&p,&q);
            now.a[0][0]=1;
            now.a[1][1]=1;
            now.a[2][2]=1;
            now.a[0][2]=p;
            now.a[1][2]=q;
        }else if(op[0]=='S'){
            double L;
            scanf("%lf",&L);
            now.a[0][0]=L;
            now.a[1][1]=L;
            now.a[2][2]=1;
        }else if(op[0]=='R'){
            double r;
            scanf("%lf",&r);
            r=r/180*PI;
            now.a[0][0]=cos(r);
            now.a[0][1]=-sin(r);
            now.a[1][0]=sin(r);
            now.a[1][1]=cos(r);
            now.a[2][2]=1;
        }
        base=now*base;
    }

    for(int i=1;i<=n;i++){
        Matrix ans;
        ans.init();
        ans.a[0][0]=x[i];
        ans.a[1][0]=y[i];
        ans.a[2][0]=1;
        ans=base*ans;
        printf("%.1f %.1f\n",ans.a[0][0],ans.a[1][0]);
    }
    return 0;
}
