// 返回y中x的个数
const int N = "Edit";
int next[N];
void initkmp(char x[], int m)
{
    int i = 0, j = next[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}
int kmp(char x[], int m, char y[], int n)
{
    int i, j, ans;
    i = j = ans = 0;
    initkmp(x, m);
    while (i < n)
    {
        while (j != -1 && y[i] != x[j]) j = next[j];
        i++, j++;
        if (j >= m) ans++, j = next[j];
    }
    return ans;
}
