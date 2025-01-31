#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;
std::vector<PII> a, b;

void solve()
{
    std::cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x, y, z, zz;
        std::cin >> x >> y >> z >> zz;
        if (z == 1 and zz == 1)
        {
            if (x < y) a.emplace_back(x, i);
            else b.emplace_back(y, i);
        }
        else if (z == 1) a.emplace_back(x, i);
        else b.emplace_back(y, i);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << a.size() << " ";
    for (auto [v, u] : a)
        std::cout << u << " ";
    std::cout << "\n";

    std::cout << b.size() << " ";
    for (auto [v, u] : b)
        std::cout << u << " ";
    std::cout << "\n";

}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T --)
    {
        solve();
    }
    return  0;
}
