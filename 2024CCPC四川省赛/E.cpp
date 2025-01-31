#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;

std::vector<std::vector<int>>vis;
std::vector<std::string> a;

void home()
{
    std::cout << "No\n";
}

void solve()
{
    std::cin >> n >> m;

    a.assign(n + 1, "");
    vis.assign(n + 1, std::vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i ++)
    {
        std::cin >> a[i];
        a[i] = " " + a[i];
    }

    if (a[1][m] != '.')
    {
        home();
        return ;
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            if (a[i][j] == 'L')
            {
                if (j == 1 or a[i][j - 1] != 'C')
                {
                    home();
                    return ;
                }
                vis[i][j - 1] ++;
            }
            else if (a[i][j] == 'R')
            {
                if (j == m or a[i][j + 1] != 'C')
                {
                    home();
                    return ;
                }
                vis[i][j + 1] ++;
            }
            else if (a[i][j] == 'U')
            {
                if (i == 1 or a[i - 1][j] != 'C')
                {
                    home();
                    return ;
                }
                vis[i - 1][j] += 1000000;
            }
            else if (a[i][j] == 'D')
            {
                if (i == n or a[i + 1][j] != 'C')
                {
                    home();
                    return ;
                }
                vis[i + 1][j] += 1000000;
            }
            else if (a[i][j] == '.' and !(i == 1 and j == m))
            {
                home ();
                return ;
            }
        }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            if (a[i][j] == 'C')
            {
                if (vis[i][j] != 1000001)
                {
                    home();
                    return ;
                }
            }
        }

    std::cout << "Yes\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T --)
    {
        solve();
    }
    return  0;
}
