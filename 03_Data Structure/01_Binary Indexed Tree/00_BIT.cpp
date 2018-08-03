// ---
// $O(\log n)$查询和修改数组的前缀和
// ---
// 注意下标应从1开始 n是全局变量
const int maxn = "Edit";
int bit[N], n;
int sum(int x)
{
    int s = 0;
    for (int i = x; i; i -= i & -i) s += bit[i];
    return s;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += i & -i) bit[i] += v;
}
