//MAXN
int nxt[MAXN];
void initkmp(char x[],int m){
    int i=0,j=nxt[0]=-1;
    while(i<m){
        while(j!=-1&&x[i]!=x[j])j=nxt[j];
        nxt[++i]=++j;
    }
}
//x:pa y:tx 
int kmp(char x[],int m,char y[],int n){
    int i,j,ans;
    i=j=ans=0;
    initkmp(x,m);
    while(i<n){
        while(j!=-1&&y[i]!=x[j])j=nxt[j];
        i++,j++;
        if(j>=m){
            ans++;
            j=nxt[j];
            //pos:i-m
        }
    }
    return ans;
}
