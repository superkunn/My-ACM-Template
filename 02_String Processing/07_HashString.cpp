//poj 3974
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int MAXN=1e6+10;
char s[MAXN];
ull a[MAXN];
ull b[MAXN];
ull base[MAXN];
inline ull H(int i, int j) {
	return (a[j] - a[i - 1] * base[j - i + 1]);
}
inline ull H2(int i, int j) {
	return (b[i] - b[j + 1] * base[j - i + 1]);
}
int main(){
    base[0]=1;
    for(int i=1;i<MAXN;i++){
        base[i]=base[i-1]*131;
    }
    int kase=0;
    for(;;){
        scanf("%s",s+1);
        if(s[1]=='E')break;
        int len=strlen(s+1);
        a[0]=b[len+1]=0;
        for(int i=1;i<=len;i++){
            a[i]=a[i-1]*131+s[i]-'a';
        }
        for(int i=len;i>=1;i--){
            b[i]=b[i+1]*131+s[i]-'a';
        }
        int ans=1;
        for(int pos=1;pos<=len;pos++){
            int l=1,r=min(pos-1,len-pos);
            while(l<=r){
                int mid=(l+r)>>1;
                if(H(pos-mid,pos-1)==H2(pos+1,pos+mid)){
                    ans=max(2*mid+1,ans);
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=1,r=min(pos-1,len-pos+1);
            while(l<=r){
                int mid=(l+r)>>1;
                if(H(pos-mid,pos-1)==H2(pos,pos+mid-1)){
                    ans=max(2*mid,ans);
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        printf("Case %d: ",++kase);
        printf("%d\n",ans);
    }
    return 0;
}
