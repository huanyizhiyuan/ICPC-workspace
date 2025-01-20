#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

int f[105][105][105];
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    std::cin >> n;
    std::vector<int>a(n + 1, 0);
    std::vector<int>sum(n + 1, 0);

    for(int i = 1;i <= n;i ++)
    {
        std::cin >> a[i];
        if(i != 1)
            sum[i] = sum[i - 1] + ksm(a[i] - a[i - 1], 2);
    }

    // 初始值。
    for(int i = 1;i <= n-1 ;i ++)
        for(int j = i + 1;j <= n;j ++)
            f[0][i][j] = sum[j] - sum[i];

    // 状态转移
    for(int i = 1;i <= n;i ++)
    {
        //保持原样。
        for(int l = 1;l <= n;l ++)
            for(int r = l;r <= n;r ++)
                f[i][l][r] = f[i - 1][l][r];

        //更新这一次的值。
        int len = 2 + i;
        for(int j = 1;j <= n - len + 1;j ++)
        {
            int l = j, r = j + len - 1;
            f[i][l][r] = std::max(f[i][l][r], ksm(a[r] - a[l], 2));
        }

        //合并长度为len的
        //l~r --> 1 ~ l l ~ r r ~ n
        for(int l = 1;l <= n - len + 1;l ++)
        {
            int r = l + len - 1;
            for(int j = 1;j <= l;j ++)
                for(int k = r;k <= n;k ++)
                    f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][l] + f[i][l][r] + f[i - 1][r][k]);
        }

        len = 3 + i;
        for(int j = 1;j <= n - len + 1;j ++)
        {
            int l = j, r = j + len - 1;
            f[i][l][r] = std::max(f[i][l][r], ksm(a[r] - a[l], 2));
        }
        for(int l = 1;l <= n - len + 1;l ++)
        {
            int r = l + len - 1;
            for(int j = 1;j <= l;j ++)
                for(int k = r;k <= n;k ++)
                    f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][l] + f[i][l][r] + f[i - 1][r][k]);
        }

        // for(int l = 1;l <= n - len + 1;l ++)
        //     for(int r = l + len - 1;r <= n;r ++)
        //         for(int k = l + len - 1;k <= r;k ++)
        //             f[i][l][r] = std::max({f[i][l][r], f[i][l][k] + f[i-1][k][r],f[i-1][l][k] + f[i][k][r]});

        // for(int l = 1;l <= n;l ++)
        //     for(int r = l;r <= n;r ++)
        //         std::cout << std::format("i = {}, l = {}, r = {}, f = {}\n", i, l, r, f[i][l][r]);
    }

    // 设置答案
    for(int i = 1;i <= n;i ++)
        std::cout << f[i][1][n] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    // std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

