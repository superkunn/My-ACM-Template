const int MAXN=2e6+100;
int z[MAXN];
char a[MAXN];
void z_algorithm(char *a,int len){
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
    z_algorithm(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",z[i]," \n"[i==n-1]);
    }
    return 0;
}
