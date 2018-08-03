ll exgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b) d = exgcd(b, a % b, y, x), y -= x * (a / b);
    else x = 1, y = 0;
    return d;
}
