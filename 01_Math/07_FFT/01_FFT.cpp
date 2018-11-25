#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<complex>
using namespace std;

typedef complex<double> cd;
const int MAXN=2094153;
const double PI=3.14159265358979;

cd a[MAXN],b[MAXN];
int rev[MAXN];
void getrev(int bit){
	for(int i=0;i<(1<<bit);i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
}

void fft(cd* a,int n,int dft){
	for(int i=0;i<n;i++){
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int step=1;step<n;step<<=1){
		cd wn=exp(cd(0,dft*PI/step));
		for(int j=0;j<n;j+=step<<1){
			cd wnk(1,0);
			for(int k=j;k<j+step;k++){
				cd x=a[k];
				cd y=wnk*a[k+step];
				a[k]=x+y;
				a[k+step]=x-y;
				wnk*=wn;
			}
		}
	}
	if(dft==-1){
		for(int i=0;i<n;i++)a[i]/=n;
	}
}

int output[MAXN];
char s1[MAXN],s2[MAXN];
int main(){
	scanf("%s%s",s1,s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	int bit=1,s=2;
	for(bit=1;(1<<bit)<l1+l2-1;bit++){
		s<<=1;
	}
	int i;
	for(i=0;i<l1;i++){
		a[i]=(double)(s1[l1-i-1]-'0');
	}
	for(i=0;i<l2;i++){
		b[i]=(double)(s2[l2-i-1]-'0');
	}
	getrev(bit);
	//dft
	fft(a,s,1);
	fft(b,s,1);
	for(i=0;i<s;i++)a[i]*=b[i];
	//idft
	fft(a,s,-1);

	for(i=0;i<s;i++){
		output[i]+=(int)(a[i].real()+0.5);
		output[i+1]+=output[i]/10;
		output[i]%=10;
	}

	for(i=l1+l2;!output[i]&&i>=0;i--){}
	if(i==-1)printf("0");
	for(;i>=0;i--){
		printf("%d",output[i]);
	}
	puts("");
	return 0;
}
