// ---
// 复杂度$O(\sqrt{n}*E)$\\
// $uN$ 为左端的顶点数,使用前赋值(点编号0开始)
// ---
const int maxn = "Edit";
vector<int> G[maxn];
int uN;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void addedge(int u, int v) { G[u].pb(v); }
bool bfs()
{
    queue<int> q;
    dis = INF;
    clr(dx, -1), clr(dy, -1);
    for (int i = 0; i < uN; i++)
        if (Mx[i] == -1)
            q.push(i), dx[i] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dx[u] > dis) break;
        for (auto& v : G[u])
        {
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool dfs(int u)
{
    for (auto& v : G[u])
    {
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || dfs(My[v]))
            {
                My[v] = u, Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    clr(Mx, -1), clr(My, -1);
    while (bfs())
    {
        clr(used, false);
        for (int i = 0; i < uN; i++)
            if (Mx[i] == -1 && dfs(i)) res++;
    }
    return res;
}
