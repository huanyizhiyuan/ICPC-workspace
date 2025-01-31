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
    if (n % 3 == 0) std::cout << 1 << " " << n / 3 << "\n";
    else std::cout << 0 << " " << n / 3 + n - n / 3 * 3 << "\n";
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
