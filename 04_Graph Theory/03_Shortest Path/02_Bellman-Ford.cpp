const int maxn = "Edit";
struct BellmanFord
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn]; // 是否在队列中
    int d[maxn];    // s到各个点的距离
    int p[maxn];    // 最短路中的上一条弧
    int cnt[maxn];  // 进队次数
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    bool bellmanford(int s)
    {
        queue<int> q;
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        inq[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[u] < INF && d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = id;
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = true;
                        if (++cnt[e.to] > n) return false;
                    }
                }
            }
        }
        return true;
    }
};
