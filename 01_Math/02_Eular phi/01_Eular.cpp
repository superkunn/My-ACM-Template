#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=10000;
int phi[MAXN];
int phi1(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}
void phi2(int n){
    for(int i=0;i<=n;i++) phi[i]=i;
    for(int i=2;i<=n;i++)
        if(phi[i]==i)
            for(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);
}
int main(){
    phi2(100);
    for(int i=1;i<=100;i++)cout<<phi1(i)<<" "<<phi[i]<<endl;
    return 0;
}
