//对于字符串a的每个后缀，匹配它与a的第一个后缀的最长公共前缀，复杂度线性
const int MAXN=2e6+100;
int z[MAXN];
char a[MAXN];
void z_alg(char *a,int len){
    z[0]=len;
    for(int i=1,j=1,k;i<len;i=k){
        if(j<i)j=i;
        while(j<len && a[j]==a[j-i])++j;
        z[i]=j-i;
        k=i+1;
        while(k+z[k-i]<j)z[k]=z[k-i],++k;
    }
}
int main(){
    /*
    b  a b $ a b a b a b
    10 0 1 0 0 3 0 3 0 1
    */
    scanf("%s",a);
    int n=strlen(a);
    z_alg(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",z[i]," \n"[i==n-1]);
    }
    return 0;
}
