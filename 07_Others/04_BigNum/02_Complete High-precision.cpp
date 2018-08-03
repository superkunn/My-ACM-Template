#define N 10000
class bint
{
private:
    int a[N]; // 用 N 控制最大位数
    int len;  // 数字长度
public:
    // 构造函数
    bint() { len = 1, clr(a, 0); }
    // int -> bint
    bint(int n)
    {
        len = 0;
        clr(a, 0);
        int d = n;
        while (n)
            d = n / 10 * 10, a[len++] = n - d, n = d / 10;
    }
    // char[] -> int
    bint(const char s[])
    {
        clr(a, 0);
        len = 0;
        int l = strlen(s);
        for (int i = l - 1; ~i; i--) a[len++] = s[i];
    }
    // 拷贝构造函数
    bint(const bint& b)
    {
        clr(a, 0);
        len = b.len;
        for (int i = 0; i < len; i++) a[i] = b.a[i];
    }
    // 重载运算符 bint = bint
    bint& operator=(const bint& n)
    {
        len = n.len;
        for (int i = 0; i < len; i++) a[i] = n.a[i];
        return *this;
    }
    // 重载运算符 bint + bint
    bint operator+(const bint& b) const
    {
        bint t(*this);
        int res = b.len > len ? b.len : len;
        for (int i = 0; i < res; i++)
        {
            t.a[i] += b.a[i];
            if (t.a[i] >= 10) t.a[i + 1]++, t.a[i] -= 10;
        }
        t.len = res + a[res] == 0;
        return t;
    }
    // 重载运算符 bint - bint
    bint operator-(const bint& b) const
    {
        bool f = *this > b;
        bint t1 = f ? *this : b;
        bint t2 = f ? b : *this;
        int res = t1.len, j;
        for (int i = 0; i < res; i++)
            if (t1.a[i] < t2.a[i])
            {
                j = i + 1;
                while (t1.a[j] == 0) j++;
                t1.a[j--]--;
                while (j > i) t1.a[j--] += 9;
                t1.a[i] += 10 - t1.a[i];
            }
            else
                t1.a[i] -= t2.a[i];
        t1.len = res;
        while (t1.a[len - 1] == 0 && t1.len > 1) t1.len--, res--;
        if (f) t1.a[res - 1] = 0 - t1.a[res - 1];
        return t1;
    }
    // 重载运算符 bint * bint
    bint operator*(const bint& b) const
    {
        bint t;
        int i, j, up, tmp, tmp1;
        for (i = 0; i < len; i++)
        {
            up = 0;
            for (j = 0; j < b.len; j++)
            {
                tmp = a[i] * b.a[j] + t.a[i + j] + up;
                if (tmp > 9)
                    tmp1 = tmp - tmp / 10 * 10, up = tmp / 10, t.a[i + j] = tmp1;
                else
                    up = 0, t.a[i + j] = tmp;
            }
            if (up) t.a[i + j] = up;
        }
        t.len = i + j;
        while (t.a[t.len - 1] == 0 && t.len > 1) t.len--;
        return t;
    }
    // 重载运算符 bint / int
    bint operator/(const int& b) const
    {
        bint t;
        int down = 0;
        for (int i = len - 1; ~i; i--)
            t.a[i] = (a[i] + down * 10) / b, down = a[i] + down * 10 - t.a[i] * b;
        t.len = len;
        while (t.a[t.len - 1] == 0 && t.len > 1) t.len--;
        return t;
    }
    // 重载运算符 bint ^ n (n次方快速幂, 需保证n非负)
    bint operator^(const int n) const
    {
        bint t(*this), rt(1);
        if (n == 0) return 1;
        if (n == 1) return *this;
        int m = n;
        for (; m; m >>= 1, t = t * t)
            if (m & 1) rt = rt * t;
        return rt;
    }
    // 重载运算符 bint > bint 比较大小
    bool operator>(const bint& b) const
    {
        int p;
        if (len > b.len) return 1;
        if (len == b.len)
        {
            p = len - 1;
            while (a[p] == b.a[p] && p >= 0) p--;
            return p >= 0 && a[p] > b.a[p];
        }
        return 0;
    }
    // 重载运算符 bint > int 比较大小
    bool operator>(const int& n) const { return *this > bint(n); }
    // 输出
    void out()
    {
        for (int i = len - 1; ~i; i--) printf("%d", a[i]);
        puts("");
    }
};
