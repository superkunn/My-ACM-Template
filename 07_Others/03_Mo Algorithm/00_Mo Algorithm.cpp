// ---
// 莫队算法,可以解决一类静态,离线区间查询问题。分成 $\sqrt{x}$ 块,分块排序。
// ---
struct query { int L, R, id; };
void solve(query node[], int m)
{
    tmp = 0;
    clr(num, 0);
    clr(ans, 0);
    sort(node, node + m, [](query a, query b) { return a.l / unit < b.l / unit || a.l / unit == b.l / unit && a.r < b.r; });
    int L = 1, R = 0;
    for (int i = 0; i < m; i++)
    {
        while (node[i].L < L) add(a[--L]);
        while (node[i].L > L) del(a[L++]);
        while (node[i].R < R) del(a[R--]);
        while (node[i].R > R) add(a[++R]);
        ans[node[i].id] = tmp;
    }
}
