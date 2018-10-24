const int MAXN=1e3+10;
int x[MAXN],y[MAXN],z[MAXN];
double dist[MAXN][MAXN],cost[MAXN][MAXN];
double dsum,csum,ans;
int n;
double len(int a,int b){
    return cost[a][b]-ans*dist[a][b];
}
void prim(){
    double dt[MAXN],ds[MAXN],dc[MAXN];
    bool vis[MAXN];
    for(int i=2;i<=n;i++){
        dt[i]=len(1,i);
        ds[i]=dist[1][i];
        dc[i]=cost[1][i];
    }
    memset(vis,0,sizeof(vis));
    vis[1]=true;
    dsum=csum=0;
    for(int i=2;i<=n;i++){
        int t=-1;
        for(int j=2;j<=n;j++){
            if(vis[j])continue;
            if(t==-1||dt[j]<dt[t])t=j;
        }
        dsum+=ds[t];
        csum+=dc[t];
        vis[t]=true;
        for(int j=2;j<=n;j++){
            if(vis[j])continue;
            if(len(t,j)<dt[j]){
                dt[j]=len(t,j);
                ds[j]=dist[t][j];
                dc[j]=cost[t][j];
            }
        }
    }
}
int main(){
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dist[i][j]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]));
                dist[j][i]=dist[i][j];
                cost[i][j]=fabs(z[i]-z[j]);
                cost[j][i]=cost[i][j];
            }
        }
        dsum=csum=0.0;
        for(int i=2;i<=n;i++)dsum+=dist[1][i],csum+=cost[1][i];
        ans=csum/dsum;
        for(;;){
            prim();
            double now=csum/dsum;
            if(fabs(now-ans)<1e-4)break;
            else ans=now;
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
