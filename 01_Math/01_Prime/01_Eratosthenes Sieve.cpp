// ---
// $O(n\log\log n)$筛出maxn内所有素数\\
// $notprime[i] = 0/1$ 0为素数 1为非素数\\
// ---
const int maxn = "Edit";
bool notprime[maxn] = {1, 1};   // 0 && 1 为非素数
void GetPrime()
{
    for (int i = 2; i < maxn; i++)
        if (!notprime[i] && i <= maxn / i)  // 筛到√n为止
            for (int j = i * i; j < maxn; j += i)
                notprime[j] = 1;
}
