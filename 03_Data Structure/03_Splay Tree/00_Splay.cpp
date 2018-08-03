#define key_value ch[ch[root][1]][0]
const int maxn = "Edit";
struct Splay
{
    int a[maxn];
    int sz[maxn], ch[maxn][2], fa[maxn];
    int key[maxn], rev[maxn];
    int root, tot;
    int stk[maxn], top;
    void init(int n)
    {
        tot = 0, top = 0;
        root = newnode(0, -1);
        ch[root][1] = newnode(root, -1);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        key_value = build(0, n - 1, ch[root][1]);
        pushup(ch[root][1]);
        pushup(root);
    }
    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k;
        rev[x] = 0;
        return x;
    }
    void pushdown(int x)
    {
        if (rev[x])
        {
            swap(ch[x][0], ch[x][1]);
            if (ch[x][0]) rev[ch[x][0]] ^= 1;
            if (ch[x][1]) rev[ch[x][1]] ^= 1;
            rev[x] = 0;
        }
    }
    void pushup(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
    void rotate(int x, int d)
    {
        int y = fa[x];
        pushdown(y), pushdown(x);
        ch[y][d ^ 1] = ch[x][d];
        fa[ch[x][d]] = y;
        if (fa[y]) ch[fa[y]][ch[fa[y]][1] == y] = x;
        fa[x] = fa[y];
        ch[x][d] = y;
        fa[y] = x;
        pushup(y);
    }
    void splay(int x, int goal = 0)
    {
        pushdown(x);
        while (fa[x] != goal)
        {
            if (fa[fa[x]] == goal)
                rotate(x, ch[fa[x]][0] == x);
            else
            {
                int y = fa[x];
                int d = ch[fa[y]][0] == y;
                ch[y][d] == x ? rotate(x, d ^ 1) : rotate(y, d);
                rotate(x, d);
            }
        }
        pushup(x);
        if (goal == 0) root = x;
    }
    int kth(int r, int k)
    {
        pushdown(r);
        int t = sz[ch[r][0]] + 1;
        if (t == k) return r;
        return t > k ? kth(ch[r][0], k) : kth(ch[r][1], k - t);
    }
    int build(int l, int r, int p)
    {
        if (l > r) return 0;
        int mid = l + r >> 1;
        int x = newnode(p, a[mid]);
        ch[x][0] = build(l, mid - 1, x);
        ch[x][1] = build(mid + 1, r, x);
        pushup(x);
        return x;
    }
    void select(int l, int r)
    {
        splay(kth(root, l), 0);
        splay(kth(ch[root][1], r - l + 2), root);
    }
    // 各种操作
};
