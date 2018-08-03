// ---
// $gcd(x,y)=1$的对数, $x \leq n, y \leq m$
// ---
ll solve(int n, int m)
{
    if (n < m) swap(n, m);
    ll ans = 0;
    for (int i = 1; i <= m; ++i) ans += (ll)mu[i] * (n / i) * (m / i);
    return ans;
}
