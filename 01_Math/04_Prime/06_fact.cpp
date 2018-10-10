int main(){
    int n;
    scanf("%d",&n);
    primes(n);
    for(int i=1;i<=cnt;i++){
        int p=prime[i],c=0;
        for(int j=n;j;j/=p)c+=j/p;
        printf("%d %d\n",p,c);
    }
    return 0;
}
