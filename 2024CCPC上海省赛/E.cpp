#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;
std::vector<int> a;

void solve()
{
    std::cin >> n;
    std::string s;
    std::cin >> s;
    a.assign(200, 0);
    for (auto v : s)
        a[std::tolower(v)] ++;
    std::cout << std::min({a['s'], a['h'] / 2, a['a'] / 2, a['n'], a['g'], a['i']}) << "\n";
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
