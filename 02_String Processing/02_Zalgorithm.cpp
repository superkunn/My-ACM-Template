const int MAXN=1e6+10;
template<typename T>
//对于字符串a的每个后缀，匹配它与a的第一个后缀的最长公共前缀，复杂度线性
void z_alg(T a[],int len,int z[]){
    z[0]=len;
    for(int i=1,j=1,k;i<len;i=k){
        if(j<i)j=i;
        while(j<len && a[j]==a[j-i])++j;
        z[i]=j-i;
        k=i+1;
        while(k+z[k-i]<j)z[k]=z[k-i],++k;
    }
}
int z[MAXN];
char s[MAXN];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    z_alg(s,len,z);
    rep(i,1,len-1){
        if(i+z[i]==len){
            rep(j,1,i-1){
                if(z[j]>=z[i]){
                    printf("%s",s+i);
                    return 0;
                }
            }
        }
    }
    puts("Just a legend");
    return 0;
}
