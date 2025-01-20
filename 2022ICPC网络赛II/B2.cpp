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
    for(int i = 1;i <= n - 1;i ++)
        for(int j = i + 1;j <= n;j ++)
        {
            f[0][i][j] = sum[j] - sum[i];
            // std::cout << std::format("i = {}, j = {}, sum = {}\n", i, j, f[0][i][j]);
        }

        // f[0][i-1][i]=ksm(a[i]-a[i-1],2);


    // 状态转移
    for(int i = 1;i <= n;i ++)
    {
        for(int l = 1;l <= n;l ++)
        {
            for(int r = l + 1;r <= n;r ++)
            {
                // 不变。
                f[i][l][r] = f[i - 1][l][r];
                // 删除
                if(r - l + 1 >= 3)
                {
                    for(int k = l + 1;k < r;k ++)
                    {
                        f[i][l][r] = std::max(f[i][l][r], f[i - 1][l][k - 1] + f[i - 1][k + 1][r] + ksm(a[k + 1] - a[k - 1], 2));
                    }
                }
                std::cout << std::format("i = {}, l = {}, r = {}, f = {}\n", i, l, r, f[i][l][r]);
                // // 又删又改
                // if(r - l + 1 >= 4)
                // {
                //     for(int k = l + 1;k < r;k ++)
                //     {

                //     }
                // }
            }
        }
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

