//poj 1456
const int SIZE=1e5;
struct Heap{
    int a[SIZE];
    int n;
    void init(){
        n=0;
    }
    void up(int p){
        while(p>1){
            if(a[p]>a[p/2]){
                swap(a[p],a[p/2]);
                p/=2;
            }else{
                break;
            }
        }
    }
    void push(int val){
        a[++n]=val;
        up(n);
    }
    int top(){
        return a[1];
    }
    void down(int p){
        int s=p*2;
        while(s<=n){
            if(s<n&&a[s]<a[s+1])s++;
            if(a[s]>a[p]){
                swap(a[s],a[p]);
                p=s;
                s=p*2;
            }else{
                break;
            }
        }
    }
    void pop(){
        a[1]=a[n--];
        down(1);
    }
}heap;
const int MAXN=1e4+10;
pii P[MAXN];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            P[i]=mp(y,x);
        }
        sort(P+1,P+1+n);
        P[0]=mp(0,0);
        int now=P[n].fi;
        heap.init();
        heap.push(P[n].se);
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            if(now==P[i].fi){
                heap.push(P[i].se);
            }else{
                int w=now-P[i].fi;
                while(heap.n!=0&&w--){
                    ans+=heap.top();
                    heap.pop();
                }
                heap.push(P[i].se);
                now=P[i].fi;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
