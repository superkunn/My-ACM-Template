typedef pair<int, PII> Edge;
vector<Edge> G;
void add_edge(int u, int v, int d) { G.pb(mp(d, mp(u, v))); }
int Kruskal(int n)
{
    init(n); // 并查集初始化
    sort(G.begin(), G.end());
    int num = 0, ret = 0;
    for (auto& e : G)
    {
        int x = e.Y.X, y = e.Y.Y;
        int d = e.X;
        if (!same(x, y))
        {
            unite(x, y);
            num++;
            ret += d;
        }
        if (num == n - 1) break;
    }
    return ret;
}
