// ---
// 利用exgcd求$a$在模$m$下的逆元，需要保证$gcd(a, m) == 1$.
// ---
ll inv(ll a, ll m)
{
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
// ---
// $a < p$ 且 $p$为素数时，有以下两种求法\\
// 费马小定理
// ---
ll inv(ll a, ll p) { return Pow(a, p - 2, p); }
// ---
// 贾志鹏线性筛
// ---
for (int i = 2; i < n; i++) inv[i] = inv[p % i] * (p - p / i) % p;
