// ---
// $gcd(a, m) == 1$.
// ---
ll inv(ll a, ll m){
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
// ---
// $a < p$ and $p$ is prime\\
// 
// ---
ll inv(ll a, ll p) { return Pow(a, p - 2, p); }
// ---

// ---
for (int i = 2; i < n; i++) inv[i] = inv[p % i] * (p - p / i) % p;
