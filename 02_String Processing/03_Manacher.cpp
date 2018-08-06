const int MAXN=3e5;//more than two times
char s[MAXN],str[MAXN];
int len1,len2,p[MAXN];
void init(){
    str[0]='$';
    str[1]='#';
    rep(i,0,len1-1){
        str[i*2+2]=s[i];
        str[i*2+3]='#';
    }
    len2=len1*2+2;
    str[len2]='*';
}
void manacher(){
    int id=0,mx=0;
    rep(i,1,len2-1){
        if(mx>i)p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(str[i+p[i]]==str[i-p[i]])p[i]++;
        if(p[i]+i>mx){
            mx=p[i]+i;
            id=i;
        }
    }
}
int work(){
    while(scanf("%s",s)!=EOF){
        len1=strlen(s);
        init();
        manacher();
        int ans=0;
        rep(i,0,len2-1){
            ans=max(ans,p[i]);
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
