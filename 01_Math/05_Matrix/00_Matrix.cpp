//hdu 1005
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MOD = 7;
struct Matrix {
    long long a[2][2];
};
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix ret;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ret.a[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                ret.a[i][j] += lhs.a[i][k] * rhs.a[k][j]%MOD;
            }
            ret.a[i][j] %= MOD;
        }
    }
    return ret;
}
int main(){
    int a,b,n;
    while(~scanf("%d%d%d",&a,&b,&n)){
        if(a==0&&b==0&&n==0)break;
        Matrix x,y;
        x.a[0][0]=0;
        x.a[0][1]=1;
        x.a[1][0]=b;
        x.a[1][1]=a;
        y.a[0][1]=y.a[1][1]=0;
        y.a[0][0]=y.a[1][0]=1;
        if(n<=2){
            puts("1");
            continue;
        }
        n-=2;
        while(n>0){
            if(n&1)y=x*y;
            x=x*x;
            n>>=1;
        }
        printf("%lld\n",y.a[1][0]%MOD);
    }
    
    return 0;
}
