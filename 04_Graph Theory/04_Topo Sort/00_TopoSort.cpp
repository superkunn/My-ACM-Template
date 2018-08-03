// ---
// 存图前记得初始化\\
// Ans排序结果，G邻接表，deg入度，map用于判断重边\\
// 排序成功返回1，存在环返回0
// ---
const int maxn = "Edit";
int Ans[maxn];
vector<int> G[maxn];
int deg[maxn];
map<PII, bool> S;
void init(int n)
{
    S.clear();
    for (int i = 0; i < n; i++) G[i].clear();
    clr(deg, 0), clr(Ans, 0);
}
void add_edge(int u, int v)
{
    if (S[mp(u, v)]) return;
    G[u].pb(v), S[mp(u, v)] = 1, deg[v]++;
}
bool Toposort(int n)
{
    int tot = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        que.pop();
        Ans[tot++] = u;
        for (auto& v : G[u])
            if (--deg[v] == 0) q.push(t);
    }
    if (tot < n - 1) return false;
    return true;
}
