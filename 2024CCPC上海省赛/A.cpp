#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;
std::vector<std::vector<int>> a;

void solve()
{
    std::cin >> n >> m;
    n ++, m ++;
    a.assign(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            for (int p = 0; p <= n; p ++)
            {
                for (int q = 0; q <= m; q ++)
                {
                    if (p + q == 0) continue ;
                    int x1, x2, x3, x4;
                    int y1, y2, y3, y4;
                    x1 = i + p, y1 = j + q;
                    x2 = x1 + q, y2 = y1 - p;
                    x3 = x2 - p, y3 = y2 - q;
                    x4 = x3 - q, y4 = y3 + p;
                    
                    if (x1 <= n and x1 >= 1 and y1 <= m and y1 >= 1
                        and x2 <= n and x2 >= 1 and y2 <= m and y2 >= 1
                        and x3 <= n and x3 >= 1 and y3 <= m and y3 >= 1
                        and x4 <= n and x4 >= 1 and y4 <= m and y4 >= 1)
                    {
                        // std::cout << std::format("i = {}, j = {}, x1 = {}, y1 = {}, x2 = {}, y2 = {}, x3 = {}, y3 = {}, x4 = {}, y4 = {}\n", i, j, x1, y1, x2, y2, x3, y3, x4, y4);
                        a[x1][y1] += 1, a[x2][y2] += 1, a[x3][y3] += 1, a[x4][y4] += 1;
                    }
                }
            }
        }
    }

    // 只有来自于平行于坐标轴的点才会被重复记录，所以我们根据坐标进行去除。
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            a[i][j] -= std::min(i - 1, j - 1);
            a[i][j] -= std::min(n - i, m - j);
            a[i][j] -= std::min(i - 1, m - j);
            a[i][j] -= std::min(n - i, j - 1);
        }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            std::cout << a[i][j] << " \n"[j == m];
}

signed main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int T = 1;
    // std::cin >> T;

    while(T --)
    {
        solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout << "运行时间: " << elapsed.count() << " ms";
    return  0;
}
