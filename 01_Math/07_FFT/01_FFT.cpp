//hdu 1402 a*b plus
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
const double PI=acos(-1.0);
struct Complex{
    double x,y;
    Complex(double _x=0.0,double _y=0.0){
        x=_x;
        y=_y;
    }
    Complex operator+(const Complex &b)const{
        return Complex(x+b.x,y+b.y);
    }
    Complex operator-(const Complex &b)const{
        return Complex(x-b.x,y-b.y);
    }
    Complex operator*(const Complex &b)const{
        return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
void change(Complex y[],int len){
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(Complex y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++){
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1){
        rep(i,0,len-1){
            y[i].x/=len;
        }
    }
}
const int MAXN=2e5+10;
char str1[MAXN],str2[MAXN];
Complex x[MAXN],y[MAXN];
int ans[MAXN];
int main(){
    while(~scanf("%s%s",str1,str2)){
        int len1=strlen(str1);
        int len2=strlen(str2);
        int len=1;
        for(;len<len1+len2;len<<=1);
        rep(i,0,len1-1){
            x[i]=Complex(str1[len1-1-i]-'0',0);
        }
        rep(i,len1,len-1){
            x[i]=Complex(0,0);
        }
        rep(i,0,len2-1){
            y[i]=Complex(str2[len2-1-i]-'0',0);
        }
        rep(i,len2,len-1){
            y[i]=Complex(0,0);
        }
        fft(x,len,1);
        fft(y,len,1);
        rep(i,0,len-1){
            x[i]=x[i]*y[i];
        }
        fft(x,len,-1);
        ans[0]=0;
        rep(i,0,len-1){
            ans[i]+=(int)(x[i].x+0.5);
            ans[i+1]=ans[i]/10;
            ans[i]%=10;
        }
        while(ans[len]==0&&len!=0)len--;
        per(i,len,0)putchar(char('0'+ans[i]));
        puts("");
    }
    return 0;
}
