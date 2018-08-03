//割顶的bccno无意义
const int maxn = "Edit";
int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];
stack<PII> s;
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void add_edge(int u, int v) { G[u].pb(v), G[v].pb(u); }
int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (auto& v : G[u])
    {
        PII e = mp(u, v);
        if (!pre[v])
        {
            //没有访问过v
            s.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv); //用后代的low函数更新自己
            if (lowv >= pre[u])
            {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear(); //注意！bcc从1开始编号
                for (;;)
                {
                    PII x = s.top();
                    s.pop();
                    if (bccno[x.X] != bcc_cnt)
                        bcc[bcc_cnt].pb(x.X), bcc[x.X] = bcc_cnt;
                    if (bccno[x.Y] != bcc_cnt)
                        bcc[bcc_cnt].pb(x.Y), bcc[x.Y] = bcc_cnt;
                    if (x.X == u && x.Y == v) break;
                }
            }
        }
        else if (pre[v] < pre[u] && v != fa)
        {
            s.push(e);
            lowu = min(lowu, pre[v]); //用反向边更新自己
        }
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    return lowu;
}
void find_bcc(int n)
{
    //调用结束后s保证为空，所以不用清空
    clr(pre, 0), clr(iscut, 0), clr(bccno, 0);
    dfs_clock = bcc_cnt = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i, -1);
}
