#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=3e5+10;
const int P=131;
char s[MAXN];
int len;
ull base[MAXN];
ull f[MAXN];
int sa[MAXN],height[MAXN];
ull H(int l,int r){
    return f[r]-f[l-1]*base[r-l+1];
}
int lcp(int x,int y){
    int l=0,r=min(len-x+1,len-y+1),ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(H(x,x+mid-1)==H(y,y+mid-1)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
bool cmp(int x,int y){
    int d=lcp(x,y);
    return s[x+d]<s[y+d];
}
void calc_height(){
    for(int i=2;i<=len;i++){
        height[i]=lcp(sa[i-1],sa[i]);
    }
}
int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    base[0]=1;
    for(int i=1;i<=len;i++){
        sa[i]=i;
        base[i]=base[i-1]*P;
        f[i]=f[i-1]*P+(s[i]-'a'+1);
    }
    sort(sa+1,sa+1+len,cmp);
    calc_height();
    for(int i=1;i<=len;i++){
        printf("%d%c",sa[i]-1," \n"[i==len]);
    }
    for(int i=1;i<=len;i++){
        printf("%d%c",height[i]," \n"[i==len]);
    }
    return 0;
}
