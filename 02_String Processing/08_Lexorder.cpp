const int MAXN=2e6+100;
char a[MAXN],b[MAXN];
int Lexorder(char *s){
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)s[n+i]=s[i];
    int i=1,j=2,k;
    while(i<=n&&j<=n){
        for(k=0;k<=n&&s[i+k]==s[j+k];k++);
        if(k==n)break;//"aaaaa"
        if(s[i+k]>s[j+k]){
            i=i+k+1;
            if(i==j)i++;
        }else{
            j=j+k+1;
            if(i==j)j++;
        }
    }
    return min(i,j);
}
int main(){
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1);
    int x=Lexorder(a);
    int y=Lexorder(b);
    for(int i=0;i<n;i++){
        int xx=x+i;
        int yy=y+i;
        if(a[xx]!=b[yy]){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for(int i=0;i<n;i++){
        int xx=x+i;
        putchar(a[xx]);
    }
    return 0;
}
