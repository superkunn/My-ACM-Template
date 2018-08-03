const int maxn = "Edit";
struct EdmonsKarp //时间复杂度O(v*E*E)
{
    int n, m;
    vector<Edge> edges;  //边数的两倍
    vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    int a[maxn];         //起点到i的可改进量
    int p[maxn];         //最短路树上p的入弧编号
    void init(int n)
    {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0)); //反向弧
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    int Maxflow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            clr(a, 0);
            queue<int> q;
            q.push(s);
            a[s] = INF;
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
