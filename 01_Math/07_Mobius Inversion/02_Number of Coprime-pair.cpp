// ---
// 有$n$个数$(n \leq 100000)$，问这$n$个数中互质的数的对数
// ---
ll solve()
{
    int b[100005];
    ll _max, ans = 0;
    clr(b, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x > _max) _max = x;
        b[x]++;
    }
    for (int i = 1; i <= _max; i++)
    {
        int cnt = 0;
        for (ll j = i; j <= _max; j += i) cnt += b[j];
        ans += 1LL * mu[i] * cnt * cnt;
    }
    return (ans - b[1]) / 2;
}
