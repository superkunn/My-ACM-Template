struct HeapNode
{
    int d, u;
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};
const int maxn = "Edit";
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[maxn]; // 每个节点出发的边编号（从0开始编号）
    bool done[maxn];     // 是否已永久标号
    int d[maxn];         // s到各点的距离
    int p[maxn];         // 最短路中的一条边
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear(); // 清空邻接表
        edges.clear();                            // 清空边表
    }
    void AddEdge(int from, int to, int dist)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.emplace_back(from, to, dist);
        m = edges.size();
        G[from].push_back(m - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        q.push({0, s});
        while (!q.empty())
        {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = id;
                    q.push({d[e.to], e.to});
                }
            }
        }
    }
};
