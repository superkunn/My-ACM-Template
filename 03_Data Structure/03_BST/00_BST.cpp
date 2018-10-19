const int SIZE=1e5+10;
struct BST{
    int l,r;
    int val;
}a[SIZE];
int tot,root,INF=1<<30;
int New(int val){
    a[++tot].val=val;
    return tot;
}
void Build(){
    New(-INF);
    New(INF);
    root=1;
    a[1].r=2;
}
int Get(int p,int val){
    if(p==0)return 0;
    if(val==a[p].val)return p;
    return val<a[p].val?Get(a[p].l,val):Get(a[p].r,val);
}
void Insert(int &p,int val){
    if(p==0){
        p=New(val);
        return;
    }
    if(val==a[p].val)return;
    if(val<a[p].val)Insert(a[p].l,val);
    else Insert(a[p].r,val);
}
int GetNext(int val){
    int ans=2;//a[2].val==INF;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].r>0){
                p=a[p].r;
                while(a[p].l>0)p=a[p].l;
                ans=p;
            }
            break;
        }
        if(a[p].val>val&&a[p].val<a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
int GetLast(int val){
    int ans=1;//a[1].val=-INF;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].l>0){
                p=a[p].l;
                while(a[p].r>0)p=a[p].r;
                ans=p;
            }
            break;
        }
        if(a[p].val<val&&a[p].val>a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return ans;
}
void Remove(int val){
    int &p=root;
    while(p){
        if(val==a[p].val)break;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    if(p==0)return;
    if(a[p].l==0){
        p=a[p].r;
    }else if(a[p].r==0){
        p=a[p].l;
    }else{
        int nxt=a[p].r;
        while(a[nxt].l>0)nxt=a[nxt].l;
        Remove(a[nxt].val);
        a[nxt].l=a[p].l;
        a[nxt].r=a[p].r;
        p=nxt;
    }
}
