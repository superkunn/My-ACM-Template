// ---
// 时间复杂度:$O(VE)$.\\
// 顶点编号从0开始
// ---
const int maxn = "Edit";
int uN, vN;        //uN是匹配左边的顶点数,vN是匹配右边的顶点数
int g[maxn][maxn]; //邻接矩阵g[i][j]表示i->j的有向边就可以了,是左边向右边的匹配
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
    for (int v = 0; v < vN; v++)
        if (g[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;
    clr(linker, -1);
    for (int u = 0; u < uN; u++)
    {
        clr(used, 0);
        if (dfs(u)) res++;
    }
    return res;
}
